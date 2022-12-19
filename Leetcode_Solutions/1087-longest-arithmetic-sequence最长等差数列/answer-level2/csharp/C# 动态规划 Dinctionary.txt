看到题目说是“最长”等差数列，那么就想到了动态规划。决定试一试。
一般这种题可以变成：dp[i] = 以A[i]结尾的等差数列的最大长度
但是再仔细一想，以A[i]结尾的等差数列可能有多个。比如[1,2,3,4,5]，以5结尾的等差数列有[1,2,3,4,5],[1,3,5]。
因为dp[i]应该是一个Dictionary，dp[i][k]表示以A[i]结尾，以k为step的等差数列的长度
我的代码就比较普通了。第一次遍历简历dp结构，第二次遍历求出最大长度。
```
public class Solution
{
    public int LongestArithSeqLength(int[] A)
    {
        var dp = new Dictionary<int, int>[A.Length];
        for (int i = 0; i < A.Length; i++)
            dp[i] = new Dictionary<int, int>();

        for (int j = 1; j < A.Length; j++)
        {
            for (int i = 0; i < j; i++)
            {
                var step = A[j] - A[i];
                if (dp[i].ContainsKey(step))
                {
                    dp[j][step] = dp[i][step] + 1;
                } else
                {
                    dp[j][step] = 2;
                }
            }
        }
        int maxlen = 0;
        for (int j = 0; j < A.Length; j++)
        {
            var dict = dp[j];
            if (dict.Count > 0)
            {
                var values = dict.Values;
                maxlen = Math.Max(maxlen, values.Max());
            }
        }
        return maxlen;
    }
}
```
