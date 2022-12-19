# dp方程分析
（初始说明：i为word1上的指针，j为word2上的指针。word1进行（删除，替换，增加）操作转换为word2）
1. word1.charAt(i) == word2.charAt(j)
相等情况时，不需要进行任何操作，等于这两个字符对操作数没有的影响时的操作数，则dp[i][j] = dp[i-1][j-1];
2. word1.charAt(i) != word2.charAt(j)
     - 插入一个字符：
     dp[i][j] = dp[i-1][j] + 1;
     - 删除一个字符：
     dp[i][j] = dp[i][j-1] + 1;
     - 替换一个字符：
     dp[i][j] = dp[i-1][j-1] + 1;
# 初始条件base case
- word1与word2都为空，则无需操作
- 若word1长度为0，则 word1一直需要插入字符
- 若word2长度为0，则 word1一直需要删除字符

```
class Solution {
    public int minDistance(String word1, String word2) {
        int[][] dp = new int[word1.length()+1][word2.length()+1];   

        //base case.
        //dp[0][0] = 0; 长度相同，无需操作
        for(int i = 0;i < dp[0].length;i++){
            //若word2长度为0，则 word1一直删除字符
            dp[0][i] = i;
        }

        for(int i = 0;i < dp.length;i++){
            //若word1长度为0，则 word1一直插入一个字符
            dp[i][0] = i;
        }

        for(int i = 1;i < dp.length;i++){
            for(int j = 1;j < dp[0].length;j++){
                /**
                *相等情况时，
                *不需要进行任何操作，
                *等于这两个字符对操作数没有的影响时的操作数，
                *则dp[i][j] = dp[i-1][j-1];
                */
                if(word1.charAt(i-1) == word2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                /**
                *不相同有3种情况：
                *i 为word1上的指针 j 为word2上的指针
                *(题目为word1转换为word2)
                *影响不大，若为 word2转word1 则1与3的方程对调
                *1、插入一个字符：
                *dp[i][j] = dp[i-1][j] + 1;
                *2、删除一个字符：
                *dp[i][j] = dp[i][j-1] + 1;
                *3、替换一个字符：
                *dp[i][j] = dp[i-1][j-1] + 1;
                */
                    dp[i][j] = Math.min(Math.min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]) + 1;
                }
            }
        }

        return dp[word1.length()][word2.length()];
    }
}
```
