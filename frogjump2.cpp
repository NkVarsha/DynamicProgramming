class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int>dp(n,-1);
        dp[0]=0;
        for(int i=1;i<n;i++){
            int mini=INT_MAX;
            for(int j=1;j<=k;j++){
                if(i>=j){
                    int jump=dp[i-j]+abs(height[i]-height[i-j]);
                    mini=min(mini,jump);
                }
            }
            dp[i]=mini;
        }
        return dp[n-1];
    }
};
/*
There are n stones and an array of heights and Geek is standing at stone 1 and can jump to one of the following: Stone i+1, i+2, ... i+k stone and cost will be [hi-hj] is incurred, where j is the stone to land on. Find the minimum possible total cost incurred before the Geek reaches Stone n.

Examples :
Input: n = 5, k = 3 heights = {10, 30, 40, 50, 20}
Output: 30
Explanation: Geek will follow the path 1->2->5, the total cost would be | 10-30| + |30-20| = 30, which is minimum

Input: n = 3, k = 1 heights = {10,20,10}
Output: 20
Explanation: Geek will follow the path 1->2->3, the total cost would be |10 - 20| + |20 - 10| = 20.

Your Task:
You don't need to read input or print anything. Your task is to complete the function minimizeCost() which takes the array height, and integer n, and integer k and returns the minimum energy that is lost.

Expected Time Complexity: O(n*k)
Expected Space Complexity: O(n)

Constraint:
2 <= n <= 103
1 <= k <= 100
1 <= heights[i] <= 104


*/
