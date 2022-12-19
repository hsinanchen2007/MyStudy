方法一 递归&&备忘录递归  超时
递归
```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return helper(triangle,0,0);
    }
    int helper(vector<vector<int>> triangle,int i,int j){
        if(i==triangle.size()-1) return triangle[i][j];
        int lt = helper(triangle,i+1,j);
        int rt = helper(triangle,i+1,j+1);
        return min(lt, rt) + triangle[i][j];
    }
};
```
备忘录递归
```
class Solution {
public:
    vector<vector<int>> a;
    int minimumTotal(vector<vector<int>>& triangle) {
        return helper(triangle,0,0);
    }
    int helper(vector<vector<int>> triangle, int i, int j){
        if(i<triangle.size()) a.emplace_back(vector<int> (triangle[i].size(),-1));
        if(a[i][j]>0) return a[i][j];
        if(i==triangle.size()-1) return a[i][j] = triangle[i][j];
        int lt = helper(triangle,i+1,j);
        int rt = helper(triangle,i+1,j+1);
        return a[i][j] = min(lt, rt) + triangle[i][j];
    }
};
```
```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle);
        for(int i=triangle.size()-2; i>=0; i--)
            for(int j=0; j<triangle[i].size(); j++) dp[i][j] = min(dp[i+1][j],dp[i+1][j+1]) + dp[i][j];
        return dp[0][0];
    }
};
```
方法二 动态规划 
自底而上，第i行的最小路径和 = 第i+1的最小路径和 + 第i行路径值
```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle);
        for(int i=triangle.size()-2; i>=0; i--) 
            for(int j=0; j<triangle[i].size(); j++) dp[i][j] = min(dp[i+1][j],dp[i+1][j+1]) + dp[i][j];
        return dp[0][0];
    }
};
```
优化，在原来数组基础上动作
```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=triangle.size()-2; i>=0; i--) 
            for(int j=0; j<triangle[i].size(); j++) 
                triangle[i][j] = min(triangle[i+1][j],triangle[i+1][j+1]) + triangle[i][j];  
        return triangle[0][0];
    }
```
空间压缩
```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size()+1,0);
        for(int i=triangle.size()-1; i>=0; i--)
            for(int j=0; j<triangle[i].size(); j++) dp[j] = min(dp[j],dp[j+1]) + triangle[i][j];
        return dp[0];
    }
};
```





