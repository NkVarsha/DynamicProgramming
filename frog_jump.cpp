/*Geek wants to climb from the 0th stair to the (n-1)th stair. At a time the Geek can climb either one or two steps. A height[N] array is also given. Whenever the geek jumps from stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.

Example:
Input:
n = 4
height = {10 20 30 10}
Output:
20
Explanation:
Geek jump from 1st to 2nd stair(|20-10| = 10 energy lost).
Then a jump from the 2nd to the last stair(|10-20| = 10 energy lost).
so, total energy lost is 20 which is the minimum.

Your Task:
You don't need to read input or print anything. Your task is to complete the function MinimumEnergy() which takes the array height, and integer n, and returns the minimum energy that is lost.

Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraint:
1<=n<=100000
1<=height[i]<=1000
*/

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,0);
        dp[0]=0;
        int one,two;
        for(int i=1;i<n;i++){
            one=dp[i-1]+abs(height[i]-height[i-1]);
            int two=INT_MAX;
            if(i>1){
                two=dp[i-2]+abs(height[i]-height[i-2]);
            }
            dp[i]=min(one,two);
        }
        return dp[n-1];
        
    }
};

//Spae optimization
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        int prev1=0,prev2=0;
        for(int i=1;i<n;i++){
            int two=INT_MAX;
            int one=prev1+abs(height[i]-height[i-1]);
            if(i>1){
                two=prev2+abs(height[i]-height[i-2]);
            }
            int curr=min(one,two);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
        
    }
};
