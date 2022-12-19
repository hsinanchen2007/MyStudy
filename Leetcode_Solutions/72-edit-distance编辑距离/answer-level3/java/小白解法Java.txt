### 解题思路
思路
>dp[i][j] 表示 word1 到 i 位置 转换成 word2 到 j 位置需要最少的步数。当 word1[i] == word2[j]，dp[i][j] = dp[i-1][j-1]；当 word1[i] != word2[j]，dp[i][j] = min(dp[i-1][j-1]，dp[i-1][j]，dp[i][j-1])+1；

其中的dp[i-1][j-1]表示代替操作，dp[i-1][j]表示删除操作，dp[i][j-1]表示插入操作。

以上的替换、删除、插入操作都是对 word1 来说的。

### 代码（自顶向下）暴力递归

```
package leetcode;

/**
 * @author god-jiang
 * @date 2020/2/19  17:08
 */
public class MinDistance {
    public int minDistance(String word1, String word2) {
        int length1 = word1.length();
        int length2 = word2.length();
        return min(word1, word2, length1, length2);
    }

    public int min(String word1, String word2, int i, int j) {
        //base case
        if (i == 0) {
            return j;
        } else if (j == 0) {
            return i;
        } else if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
            return min(word1, word2, i - 1, j - 1);
        } else {
            int len1 = min(word1, word2, i - 1, j - 1) + 1;
            int len2 = min(word1, word2, i - 1, j) + 1;
            int len3 = min(word1, word2, i, j - 1) + 1;
            return Math.min(Math.min(len1, len2), len3);
        }
    }
}
```



因为有重复计算的过程，而且无后效性。即一个函数f(n)一旦确定，那么之后就可以直接调用它的值，不用再关心f(n)的计算过程了，这个就是无后效性。

### 代码（自底向上）动态规划

```
package leetcode;

/**
 * @author god-jiang
 * @date 2020/2/19  17:08
 */
public class MinDistance {
        public int minDistance(String word1, String word2) {
            int length1 = word1.length();
            int length2 = word2.length();
            int[][] dp = new int[length1 + 1][length2 + 1];
            //初始化base case
            for (int i = 1; i <= length1; i++) {
                dp[i][0] = dp[i - 1][0] + 1;
            }
            for (int j = 1; j <= length2; j++) {
                dp[0][j] = dp[0][j - 1] + 1;
            }
            //填充二维数组dp表
            for (int i = 1; i <= length1; i++) {
                for (int j = 1; j <= length2; j++) {
                    if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = Math.min(Math.min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                    }
                }
            }
            return dp[length1][length2];
        }
}
```


基本上动态规划都是暴力递归改过来的。最长公共子序列、凑硬币等都是通过这种方法写出动态规划的状态转移方程。没有必要去背状态转移方程式，也不用一直想着最优子结构等名词。最需要写出暴力递归，观察能不能改动态规划即可。

递归就是“暴力的枚举”，期间可能包括一大堆重复计算，而且一般时间复杂度都是O(2^N)。改成动态规划就是“聪明的枚举”，可以省掉重复的计算。

### 代码

```java
class Solution {
    public int minDistance(String word1, String word2) {
        int[][] dp=new int[word1.length()+1][word2.length()+1];
        for(int i=1;i<=word1.length();i++){
            dp[i][0]=dp[i-1][0]+1;
        }
        for(int j=1;j<=word2.length();j++){
            dp[0][j]=dp[0][j-1]+1;
        }

        for(int i=1;i<=word1.length();i++){
            for(int j=1;j<=word2.length();j++){
                if(word1.charAt(i-1)==word2.charAt(j-1)){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=Math.min(Math.min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
                }
            }
        }
        return dp[word1.length()][word2.length()];
    }
}
```

觉得我还写得好的可以关注知乎:god-jiang。我有整理动态规划的解题思路和套路。谢谢支持