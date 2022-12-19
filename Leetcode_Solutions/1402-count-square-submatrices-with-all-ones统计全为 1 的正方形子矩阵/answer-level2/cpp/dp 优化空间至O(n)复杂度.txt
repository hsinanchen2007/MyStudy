执行结果：通过 显示详情
执行用时 :56 ms, 在所有 cpp 提交中击败了100.00%的用户
内存消耗 :15.9 MB, 在所有 cpp 提交中击败了100.00%的用户

![f4ab84cf1059b98caa3ec1eb590853850b64626838f425b921e03856f988bf09-image.png](https://pic.leetcode-cn.com/f789b1c43048fcd1da08ecbee24abe0f757ff9c636bd61c85b68b2fd62d72789-f4ab84cf1059b98caa3ec1eb590853850b64626838f425b921e03856f988bf09-image.png)


参考的是[221最大正方形](https://leetcode-cn.com/problems/maximal-square/)问题，建议做完那题看完官方dp优化，非常巧妙的利用了空间。
```
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m==0) return 0;
        int n = matrix[0].size();
        int re = 0;
        int pre = 0;
        vector<int> dp(n+1,0);
        for(int i =1;i<=m;i++){
            for(int j =1;j<=n;j++){
                int temp = dp[j];
                if(matrix[i-1][j-1]==1){
                    dp[j] = min(min(dp[j],dp[j-1]),pre) + 1;
                    re += dp[j];
                }else dp[j] = 0;
                pre = temp;
            }
        }
        return re;
    }
};
```
