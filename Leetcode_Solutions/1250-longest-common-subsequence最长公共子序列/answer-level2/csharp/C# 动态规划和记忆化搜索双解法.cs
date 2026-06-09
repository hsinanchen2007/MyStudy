### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    int [,] memo;
    public int Helper(string text1, string text2, int strat, int end){
        if(strat >= text1.Length || end >= text2.Length) return 0;

        if(memo[strat, end] != 0) return memo[strat, end];
        int res = 0;
        if(text1[strat] == text2[end]){
            res = Helper(text1, text2, strat + 1, end + 1) + 1; //当前位置相等时都前进一步
        }else{
            //否则开始位置前进一步或者结束位置前进一步取最大
           res = Math.Max(Helper(text1, text2, strat + 1, end), Helper(text1, text2, strat, end + 1));
        }
        memo[strat, end] = res;
        return res;
    }

    public int LongestCommonSubsequence(string text1, string text2) {
        //动态规划 dp[i,j] 表示tex1中以第i个结尾和tex2中以第j个结尾的最长公共子序列长度
        if(text1.Length == 0 || text2.Length == 0) return 0;
        int [,]dp = new int[text1.Length + 1, text2.Length + 1];

        for(int i = 1; i < text1.Length + 1; i++){
            for(int j = 1; j < text2.Length + 1; j++){
                if(text1[i - 1] == text2[j - 1]){
                    dp[i,j] = dp[i - 1,j - 1] + 1;
                }else{
                    dp[i,j] = Math.Max(dp[i-1,j], dp[i, j - 1]);
                }
            }
        }

        return dp[text1.Length, text2.Length];

        //递归-记忆化搜索
        memo = new int[text1.Length + 1, text2.Length + 1];
        return Helper(text1, text2, 0, 0);
    }
}
```