发现这里C#版的题解很少，于是为了推广当下最优雅的语言C#，我来了。

DP，未压缩状态空间的解法。
具体分析参考高赞非官方题解。

```
public class Solution
{
    /*
        动态规划
        1. 缓存值含义
        2. 递推式寻找
        3. 计算初始值
        4. 画二维图优化
        * 
        * 定义: bool dp[i, j] ,表示 Si ... Sj 是回文
        * 递推式: dp[i, j] = { true , s[i] == s[j] && dp[i+1, j-1]
        *                    { false
        *         一个隐含条件, j - i + 1 <= 3, 可以立刻判断当首尾相同时，是否回文（而不用去找上一个值）
        *         //考虑一个事实，i=j时 dp[i, j] 恒为true，当区间在1、2、3长度时，必然直接得出结论
        * 初始值: dp[0,0] = true
    */
    public string LongestPalindrome(string s)
    {
        int len = s.Length;
        if (len < 2)
            return s;

        bool[,] dp = new bool[len, len];
        dp[0, 0] = true;
        int maxLen = 1, start = 0;

        for (int j = 1; j < len; j++)
        {
            for(int i = 0; i < j; i++)
            {
                dp[i, j] = s[i] == s[j] && (j - i < 3 || dp[i+1, j-1]);
                if(dp[i, j])
                {
                    int curLen = j - i + 1;
                    if(curLen > maxLen)
                    {
                        maxLen = curLen;
                        start = i;
                    }
                }
            }
        }

        return s.Substring(start, maxLen);
    }
}
```
