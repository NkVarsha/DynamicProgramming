/*
Geek is going for n day training program. He can perform any one of these three activities Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Help Geek to maximize his merit points as you are given a 2D array of points points, corresponding to each day and activity.

Example:
Input:
n = 3
points = [[1,2,5],[3,1,1],[3,3,3]]
Output:
11
Explanation:
Geek will learn a new move and earn 5 point then on second
day he will do running and earn 3 point and on third day
he will do fighting and earn 3 points so, maximum point is 11.

Example:
Input:
n = 3
points = [[1,2,5],[3,1,1],[3,2,3]]
Output:
11
Explanation:
Geek will learn a new move and earn 5 point then on second
day he will do running and earn 3 point and on third day
he will do learning and earn 3 points so, maximum point is 11.

Your Task:
You don't have to read input or print anything. Your task is to complete the function maximumPoints() which takes the integer n and a 2D array points and returns the maximum points he can earn.

Expected Time Complexity: O(3*n)
Expected Space Complexity: O(3*n)

Constraint:
1 <=  n <= 105
1 <=  point[i] <= 100

*/


class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n,vector<int>(4,0));
        dp[0][0]=max(points[0][1],points[0][2]);
        dp[0][1]=max(points[0][0],points[0][2]);
        dp[0][2]=max(points[0][1],points[0][0]);
        dp[0][3]=max(points[0][1],max(points[0][3],points[0][2]));
        
        for(int day=1;day<n;day++){
            for(int last=0;last<4;last++){
                dp[day][last]=0;
                for(int task=0;task<3;task++){
                    if(task!=last){
                        dp[day][last]=max(dp[day][last],points[day][task]+dp[day-1][task]);
                    }
                }
            }
        }
        return dp[n-1][3];
    }
};



class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<int> prev(4,0);
        prev[0]=max(points[0][1],points[0][2]);
        prev[1]=max(points[0][0],points[0][2]);
        prev[2]=max(points[0][1],points[0][0]);
        prev[3]=max(points[0][1],max(points[0][3],points[0][2]));
        
        for(int day=1;day<n;day++){
            vector<int> temp(4,0);
            for(int last=0;last<4;last++){
                temp[last]=0;
                for(int task=0;task<3;task++){
                    if(task!=last){
                        temp[last]=max(temp[last],points[day][task]+prev[task]);
                    }
                }
            }
            prev=temp;
        }
        return prev[3];
    }
};
