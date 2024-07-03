class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]= dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};


//Space optimizaion
class Solution {
public:
    int climbStairs(int n) {
        int prev1=1,prev2=1,curr;
        for(int i=2;i<=n;i++){
            curr=prev1+prev2;
            prev1=prev2;
            prev2=curr;
        }
        return prev2;
    }
};
