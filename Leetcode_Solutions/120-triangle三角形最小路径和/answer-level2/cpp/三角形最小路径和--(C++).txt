解法一：二维动归。设dp为三角形的最小路径和
则: dp[i][j] = (dp[i+1][j] < dp[i+1][j+1] ? dp[i+1][j] : dp[i+1][j+1]) + triangle[i][j]。空间复杂度为1+2+...+n O(n方)

###代码
```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // 设第 dp[i][j]为最优解
        // dp[i][j] = min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j]  (j > 0)
        // dp[i][j] = dp[i-1][j]+triangle[i][j] (j == 0)
        //临界值: dp[0][0] = triangle[0][0]
        //       dp[1][0] = triangle[1][0]  dp[1][1] = triangle[1][1]
        if (triangle.size() == 0)   return 0;
        vector<vector<int>> dp;
        vector<int> result;

        for (int i = 0; i < triangle.size(); i++){//初始化dp
            dp.push_back(vector<int>());
            for (int j = 0; j < triangle[i].size(); j++)
                dp[i].push_back(0);
        }
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++){
            dp.push_back(vector<int>());
            for (int j = 0; j < triangle[i].size(); j++){
                if (j == 0)
                    dp[i][j] = dp[i-1][j]+triangle[i][j];
                else if (j > 0 && j < triangle[i].size()-1)                
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
                else if(j == triangle[i].size()-1)
                    dp[i][j] = dp[i-1][j-1]+triangle[i][j];
            }            
        }
        result = dp[triangle.size()-1];
        sort(result.begin(), result.end());
        return result[0];
            
        
    }
};
```

解法二：一维动归。题目说明可O(n)的空间复杂度,又考虑到dp[i][j]经过dp[i+1][j+1],第i层从i+1层计算所得，计算完，i+1层就没用了，空间开始浪费。能不能利用这一块空间储存i层的最小路径呢？

存储倒数第二行时，我们只需要前面的n-1个空间……以此类推，第一行只需要一个空间来存储最小路径和，这也正是我们要求解的结果。

###代码
```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp = triangle[triangle.size()-1]; // 倒数第二行开始计算
        for (int i = triangle.size() - 2; i >= 0 ; i--){ // 自底向上
            for (int j = 0; j <= i; j++){ 
                dp[j] = (dp[j] < dp[j+1] ? dp[j] : dp[j+1]) + triangle[i][j];
            }            
        }

        return dp[0];
    }
};
```
