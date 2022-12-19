学习并参考了大神们的题解和分析，加上了我自己的部分理解，希望能对大家理解该题有所帮助


1. 状态表示：`dp[i][j]`表示`word1`的前`i`个字符转换为`word2`的前`j`个字符所使用的最少操作数
2. 状态计算：
   如果`word1`的当前字符和`word2`的当前字符一样时，无需操作：`dp[i][j] = dp[i-1][j-1]`
   如果二者不相等时：
   1）插入：`dp[i][j] = dp[i][j-1] + 1` 表示`word1`当中的前i个字符都被用掉去转换成`word2`的前`j`个字符了，所以`word1`要补上（即插入）一个等于`word2`的第`j`个字符的字符，才能完成`word1`中的前`i`个字符转换成`word2`中的前`j`个字符
   2）删除：`dp[i][j] = dp[i-1][j] + 1` 表示`word1`中的前`i-1`个字符已经转换成了`word2`中的前`j`个字符，所有`word1`中的第`i`个字符删掉，才能完成`word1`中的前`i`个字符转换成`word2`中的前`j`个字符
   3）替换：`dp[i][j] = dp[i-1][j-1] + 1` 表示`word1`中的前`i-1`个字符已经转换成了`word2`中的前`j-1`个字符，所以应该让`word1`当前的第`i`个字符应该替换成`word2`中的第`j`个字符，才能完成`word1`中的前i个字符转换成`word2`中的前`j`个字符
   综合1）2）3）得到：
  ` dp[i][j] = min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])+1`




```
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1 == "" && word2 == "")
            return 0;
        int len1 = word1.size();
        int len2 = word2.size();
        int dp[len1+1][len2+1];

        //word2为空时，word1要不断删除
        for(int i = 0;i <= len1;i++)
            dp[i][0] = i;

        //word1为空时，word1要不断插入
        for(int i = 0; i <= len2;i++)
            dp[0][i] = i;
        
        for(int i = 1;i <= len1;i++)
        {
            for(int j = 1;j <= len2;j++)
            {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
            }
        }
        return dp[len1][len2];
    }
};
```
