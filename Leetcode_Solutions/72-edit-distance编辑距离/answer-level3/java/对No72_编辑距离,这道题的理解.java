### 解题思路
参考了解题, 其实从前往后和从后往前的新增和删除操作的dp数组是不同的.这点需要注意下, 一定要在理解了解题后才能注意到, 不能一味的迷信解题. 

### 代码

```java


class Solution {
    public int minDistance(String word1, String word2) {
        char[] a1 = word1.toCharArray();
        char[] a2 = word2.toCharArray();
        int[][] dp = new int[a1.length + 1][a2.length + 1];
        //dp[i][j]表示array1的前i个元素和array2的前j个元素匹配后的最小步数。包括i，j。
        //如果a1的i==a2的j，则dp[i][j]=dp[i-1][j-1];否则,就要看这个地方是取(新增,删除,修改)的最小值+1.
        for (int i = 0; i < a2.length; i++) {
            dp[0][i + 1] = i + 1;// 新增
        }
        for (int i = 0; i < a1.length; i++) {
            dp[i + 1][0] = i + 1;// 删除
        }
        for (int i = 0; i < a1.length; i++) {
            for (int j = 0; j < a2.length; j++) {
                if (a1[i] == a2[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    //delete dp[i+1][j+1]=dp[i+1][j]+1;
                    //update dp[i+1][j+1]=dp[i][j]+1;
                    //insert dp[i+1][j+1]=dp[i][j+1]+1;
                    dp[i + 1][j + 1] = myMin(dp[i][j + 1], dp[i][j], dp[i + 1][j]) + 1;
                }
            }
        }
        return dp[a1.length][a2.length];
    }

    private int myMin(int a, int b, int c) {
        return Math.min(Math.min(a, b), c);
    }
}

```