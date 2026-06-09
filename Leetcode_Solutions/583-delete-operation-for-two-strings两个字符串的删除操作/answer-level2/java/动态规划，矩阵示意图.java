可以转换为求两字符串最大有序公共子序列长度问题

   

```
class Solution {
//    dp示意图如下,状态转移方程可以根据示意图自行推导 

//        w o r d
//      0 0 0 0 0
//    w 0 1 1 1 1
//    r 0 1 1 2 2
//    a 0 1 1 2 2
//    d 0 1 1 2 3

    public int minDistance(String word1, String word2) {
        char[] word1Arr = word1.toCharArray();
        char[] word2Arr = word2.toCharArray();
        //类似dp编辑距离
        //dp[i][j]表示 word1(0 ~ i-1) 与 word2(0 ~ j-1) 的最大有序公共子序列长度
        int[][] dp = new int[word1Arr.length + 1][word2Arr.length + 1];
        //ini dp[0][x] = dp[y][0] = 0 空字符串没有公共子序列
        //开始累积
        for(int i = 1; i <= word1Arr.length; i++){
            for(int j = 1; j <= word2Arr.length; j++){
                if(word1Arr[i - 1] == word2Arr[j - 1]){
                    //最新叠加的两个字符相等，相当于两个当前后移一位的字符串最大有序公共子序列长度 + 1
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    //最新叠加的两个字符不相等，取max(分别后移一位的字符串最大公共子序列长度)
                    dp[i][j] = Math.max(dp[i - 1][j],dp[i][j - 1]);
                }
            }
        }
        //删减的最小步数 = 两个字符串总长度 - 两个无需删减的最长子序列长度
        return word1Arr.length + word2Arr.length - 2 * dp[word1Arr.length][word2Arr.length];
    }
}
```
