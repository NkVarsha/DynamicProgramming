class Solution {
public:
//Space optimization
    int rob(vector<int>& nums) {
        int n=nums.size();
        int temp1,temp2,curr;
        temp1=nums[0];
        temp2=0;
        for(int i=1;i<n;i++){
            int p=nums[i]+ ((i>1)?temp2:0);
            int np=0+temp1;
            curr=max(p,np);
            temp2=temp1;
            temp1=curr;
        }
        return temp1;
    }

};



//tabulation
int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int p=nums[i]+ ((i>1)?dp[i-2]:0);
            int np=0+dp[i-1];
            dp[i]=max(p,np);
        }
        return dp[n-1];
    }






/*

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

*/
