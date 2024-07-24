class Solution {
public:
    int f(vector<int>&nums){
        int t1=nums[0],t2=0,curr;
        int n=nums.size();
        for(int i=1;i<n;i++){
            int p=nums[i]+((i>1)?t2:0);
            int np=0+t1;
            curr=max(p,np);
            t2=t1;
            t1=curr;
        }
        return t1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>nums1,nums2;
        nums1.push_back(nums[0]);
        for(int i=1;i<n-1;i++){
            nums1.push_back(nums[i]);
            nums2.push_back(nums[i]);
        } 
        nums2.push_back(nums[n-1]);
        return max(f(nums1),f(nums2));
    }
};











/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 3:

Input: nums = [1,2,3]
Output: 3

 

Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 1000

*/
