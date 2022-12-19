其实就是三步走
 1.首先定义二维数组的含义：
    dp[i][j]代表i长度的word1字符串转变为j长度的Word2需要的最小操作数
2.找出子结构
    (1)当word1字符串的第i个字符与word2的第j个字符相同，就不需要转换。
        dp[i][j] = dp[i-1][j-1]
    (2)当word1字符串的第i个字符与word2的第j个字符不同，有三种操作。
        1）删除一个字符(将i处字符删除，也就是用i-1长度的word1与j长度的word2比较)
            dp[i][j] = dp[i-1][j]+1
        2)插入一个字符（在i处字符后插入与word2[j]相同的字符，剩下就是i长度的word1与j-1长度的word2比较）
            dp[i][j] = dp[i][j-1]+1
        3）替换一个字符(i处字符替换为与j相同的字符，剩下比较i-1长度的word1与j-1长度的word2)
            dp[i][j] = dp[i-1][j-1]+1
            Max(上面三种情况)
3.初始情况：
    只要i或者j为0，就全部替换为对方长度。
```
class Solution {
    public int minDistance(String word1, String word2) {
        char[]word1Array = word1.toCharArray();
        char[]word2Array = word2.toCharArray();
        int[][]dp = new int[word1Array.length+1][word2Array.length+1];
        //当word2长度为0时，就把word1的全部删除即可
        for(int i=1;i<=word1Array.length;i++)
        {
            dp[i][0] = i;
        }
        //当word1长度为0时，就插入所有word2的字符即可
        for(int j=1;j<=word2Array.length;j++)
        {
            dp[0][j] = j;
        }
        for(int i=1;i<=word1Array.length;i++)
        {
            for(int j=1;j<=word2Array.length;j++)
            {
                //第i个字符代表的是下标为i-1
                if(word1Array[i-1]==word2Array[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else{
                    //在i处插入一个字符
                    int insert = dp[i][j-1]+1;
                    //替换一个字符
                    int change = dp[i-1][j-1]+1;
                    //删除一个字符
                    int delte = dp[i-1][j]+1;
                    dp[i][j] = Math.min(Math.min(insert,change),delte);
                }
            }
        }
        return dp[word1Array.length][word2Array.length];
    }
}
```
