思路过程可以如下：  
需要求解的是word1编辑到word2所需要的步骤最小值，是不是可以先把word1的一个子串编辑成word2的一个子串？然后随着子串的长度逐渐变大，是否可以推导出结果？

用W1Si表示word1的子串（sub(0, i))，W2Sj表示word2的子串（sub(0, j))；  
二维数组dp[i][j] 代表把 W1Si编辑成 W2Sj所需要的最少步数；  

假如现在word1为horse，word2为ros；  
把horse转化为ros，可以转换思路，可在已知以下三种情况之下，再做一个额外的操作，实现把horse编辑为ros:  
1、当前已经有hors编辑为ros的步骤，那么可以在原word1（horse）基础之上，删除最后的e，也可以得到ros；  
2、当前已经有horse编辑成ro的步骤，那么可以在原word1（horse）基础之上，插入一个s，也可以得到ros；  
3、当前已经有了hors编辑成ro的步骤，那么可以在原word1（horse）基础之上，把最后的一个e替换成s，也可以得到ros;  
特殊情况下：  
hors->ros，其实就等于hor->ro;  

#状态转移方程  
那么就可以认为上面三种情况下最小值，就是最终结果：  
dp(horse->ros) = min{dp(hors->ros), dp(horse->ro), dp(hors->ro)} + 1;  
即：dp[i][j] = min(dp[i-1][j],  dp[i][j-1],  dp[i-1][j-1]) + 1;  
特殊情况下：  
如果word1[i]==word2[j]，那么dp[i][j]=dp[i-1][j-1];  

#边界
现在来看边界：  
边界是i=0或者j=0；  
如果i=0，表示从horse的一个空子串（“”）编辑成ros的所有子串（""、“r”、“ro”、“ros”）所需要的步数，每一个都执行插入就可以了，结果为dp[0][j] = j；  
如果j=0，表示从horse的所有子串（“”、“h”、“ho”、“hor”、"hors"、“horse”）编辑成ros的一个空子串（“”）所需要的步数，每一步都执行删除就可以了，结果为dp[i][0]=i；  

```
class Solution {
    public int minDistance(String word1, String word2) {
        int size1 = word1.length();
        int size2 = word2.length();
        
        //子串都应包含空串，所以长度都+1
        int[][] dp = new int[size1 + 1][size2 + 1];
        
        for (int i = 0; i <= size1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= size2; j++) {
            dp[0][j] = j;
        }
        
        //都从不为空串的第一个子串开始
        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <=size2; j++) {
                if (word1.charAt(i-1) == word2.charAt(j-1)) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    
                    dp[i][j] = Math.min(Math.min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]) + 1;
                }
            }
        }
        return dp[size1][size2];
            
    }
}
```
