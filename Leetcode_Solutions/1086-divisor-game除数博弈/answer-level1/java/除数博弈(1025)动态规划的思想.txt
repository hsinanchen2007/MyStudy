### 解题思路
核心是这句话
"选出任一 x，满足 0 < x < N 且 N % x == 0 。用 N - x 替换黑板上的数字 N 。如果玩家无法执行这些操作，就会输掉游戏。”
按照按照动态规划的思路，如果N之前的操作中存在着无法完成（N % x == 0 。用 N - x 替换黑板上的数字 N）的操作时，那么这次一定可以完成。如果存在可以完成的操作，则这次必然不能完成。
### 代码

```java
class Solution {
    public boolean divisorGame(int N) {
        boolean[] dp = new boolean[N + 1];//初始化均为false
        for (int i = 2; i <= N; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if(i % j == 0 && dp[i - j] == false)
                {
                    dp[i] = true;
                }
            }
        }
        return dp[N];
    }
}
```