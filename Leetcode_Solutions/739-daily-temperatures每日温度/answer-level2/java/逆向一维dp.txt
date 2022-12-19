### 解题思路
此处撰写解题思路
逆向dp
执行用时 :
4 ms
, 在所有 Java 提交中击败了
99.38%
的用户
内存消耗 :
47.5 MB
, 在所有 Java 提交中击败了
5.16%
的用户
### 代码

```java
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int len = T.length;
        int[] dp = new int[len];
        dp[len - 1] = 0;
        int j = 0;
        for (int i = len - 2; i >= 0; i--){
            j = i + 1;
            while (j < len){
                if (T[i] < T[j]){
                    dp[i] = j - i;
                    break;
                }else if (dp[j] == 0){
                    dp[i] = 0;
                    break;
                }else j = j + dp[j];
            }
        }
        return dp;
    }
}
```