/*
2389. Longest Subsequence With Limited Sum

You are given an integer array nums of length n, and an integer array queries of length m.

Return an array answer of length m where answer[i] is the maximum size of a subsequence that you can take from nums such that the sum of its elements is less than or equal to queries[i].

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.


Input: nums = [4,5,2,1], queries = [3,10,21]
Output: [2,3,4]
Explanation: We answer the queries as follows:
- The subsequence [2,1] has a sum less than or equal to 3. It can be proven that 2 is the maximum size of such a subsequence, so answer[0] = 2.
- The subsequence [4,5,1] has a sum less than or equal to 10. It can be proven that 3 is the maximum size of such a subsequence, so answer[1] = 3.
- The subsequence [4,5,2,1] has a sum less than or equal to 21. It can be proven that 4 is the maximum size of such a subsequence, so answer[2] = 4.

Input: nums = [2,3,4,5], queries = [1]
Output: [0]
Explanation: The empty subsequence is the only subsequence that has a sum less than or equal to 1, so answer[0] = 0.
*/


class Solution {
public:
    int lower_bound(int *v, int l, int r, int key)
    {
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }
 
    if(v[r]>key) return l;
    else return r;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int>ans;
        int n = nums.size();
        int arr[n];
        
        for(int i=0;i<nums.size();i++) 
            arr[i]=nums[i];
        for(int i=1;i<n;i++) arr[i]+=arr[i-1];
        for(int i=0;i<queries.size();i++) {
            if(queries[i]>=arr[0]) {
                int lower = lower_bound(arr,0,n-1,queries[i]);
                ans.push_back(lower+1);
            } else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};
