#### 方法一：动态规划

**思路**

让我们改变游戏规则，使得每当李得分时，都会从亚历克斯的分数中扣除。

令 `dp(i, j)` 为亚历克斯可以获得的最大分数，其中剩下的堆中的石子数是 `piles[i], piles[i+1], ..., piles[j]`。

这在比分游戏中很自然：我们想知道游戏中每个位置的值。

我们可以根据 `dp(i + 1，j)` 和 `dp(i，j-1)` 来制定 `dp(i，j)` 的递归，我们可以使用动态编程以不重复这个递归中的工作。该方法可以输出正确的答案，因为状态形成一个DAG（有向无环图）。

**算法**

当剩下的堆的石子数是 `piles[i], piles[i+1], ..., piles[j]` 时，轮到的玩家最多有 2 种行为。

可以通过比较 `j-i`和 `N modulo 2` 来找出轮到的人。

如果玩家是亚历克斯，那么她将取走 `piles[i]` 或 `piles[j]` 颗石子，增加她的分数。

之后，总分为 `piles[i] + dp(i+1, j)` 或 `piles[j] + dp(i, j-1)`；我们想要其中的最大可能得分。

如果玩家是李，那么他将取走 `piles[i]` 或 `piles[j]` 颗石子，减少亚历克斯这一数量的分数。

之后，总分为 `-piles[i] + dp(i+1, j)` 或 `-piles[j] + dp(i, j-1)`；我们想要其中的*最小*可能得分。


```cpp [wCUmzN4f-C++]
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int N = piles.size();

        // dp[i+1][j+1] = the value of the game [piles[i], ..., piles[j]]
        int dp[N+2][N+2];
        memset(dp, 0, sizeof(dp));

        for (int size = 1; size <= N; ++size)
            for (int i = 0, j = size - 1; j < N; ++i, ++j) {
                int parity = (j + i + N) % 2;  // j - i - N; but +x = -x (mod 2)
                if (parity == 1)
                    dp[i+1][j+1] = max(piles[i] + dp[i+2][j+1], piles[j] + dp[i+1][j]);
                else
                    dp[i+1][j+1] = min(-piles[i] + dp[i+2][j+1], -piles[j] + dp[i+1][j]);
            }

        return dp[1][N] > 0;
    }
};
```
```java [wCUmzN4f-Java]
class Solution {
    public boolean stoneGame(int[] piles) {
        int N = piles.length;

        // dp[i+1][j+1] = the value of the game [piles[i], ..., piles[j]].
        int[][] dp = new int[N+2][N+2];
        for (int size = 1; size <= N; ++size)
            for (int i = 0; i + size <= N; ++i) {
                int j = i + size - 1;
                int parity = (j + i + N) % 2;  // j - i - N; but +x = -x (mod 2)
                if (parity == 1)
                    dp[i+1][j+1] = Math.max(piles[i] + dp[i+2][j+1], piles[j] + dp[i+1][j]);
                else
                    dp[i+1][j+1] = Math.min(-piles[i] + dp[i+2][j+1], -piles[j] + dp[i+1][j]);
            }

        return dp[1][N] > 0;
    }
}
```
```javascript [wCUmzN4f-JavaScript]
var stoneGame = function(piles) {
    const N = piles.length;
    // Make a (N+2) by (N+2) array, initialized with 0s.
    const dp = Array(N + 2).fill(0).map(() => Array(N + 2).fill(0));

    // dp[i+1][j+1] = the value of the game [piles[i], ..., piles[j]]
    for (let size = 1; size <= N; ++size)
        for (let i = 0, j = size - 1; j < N; ++i, ++j) {
            let parity = (j + i + N) % 2;  // j - i - N; but +x = -x (mod 2)
            if (parity == 1)
                dp[i+1][j+1] = Math.max(piles[i] + dp[i+2][j+1], piles[j] + dp[i+1][j]);
            else
                dp[i+1][j+1] = Math.min(-piles[i] + dp[i+2][j+1], -piles[j] + dp[i+1][j]);
        }

    return dp[1][N] > 0;
};
```
```python3 [wCUmzN4f-Python3]
from functools import lru_cache

class Solution:
    def stoneGame(self, piles):
        N = len(piles)

        @lru_cache(None)
        def dp(i, j):
            # The value of the game [piles[i], piles[i+1], ..., piles[j]].
            if i > j: return 0
            parity = (j - i - N) % 2
            if parity == 1:  # first player
                return max(piles[i] + dp(i+1,j), piles[j] + dp(i,j-1))
            else:
                return min(-piles[i] + dp(i+1,j), -piles[j] + dp(i,j-1))

        return dp(0, N - 1) > 0
```


**复杂度分析**

* 时间复杂度：$O(N^2)$，其中 $N$ 是石子堆的数目。
* 空间复杂度：$O(N^2)$，该空间用以存储每个子游戏的中间结果。






---
#### 方法二：数学

**思路和算法**

显然，亚历克斯总是赢得 2 堆时的游戏。 通过一些努力，我们可以获知她总是赢得 4 堆时的游戏。

如果亚历克斯最初获得第一堆，她总是可以拿第三堆。 如果她最初取到第四堆，她总是可以取第二堆。`第一 + 第三`，`第二 + 第四` 中的至少一组是更大的，所以她总能获胜。

我们可以将这个想法扩展到 `N` 堆的情况下。设第一、第三、第五、第七桩是白色的，第二、第四、第六、第八桩是黑色的。 亚历克斯总是可以拿到所有白色桩或所有黑色桩，其中一种颜色具有的石头数量必定大于另一种颜色的。

因此，亚历克斯总能赢得比赛。

```cpp [B4YhLudQ-C++]
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
```
```java [B4YhLudQ-Java]
class Solution {
    public boolean stoneGame(int[] piles) {
        return true;
    }
}
```
```python [B4YhLudQ-Python]
class Solution:
    def stoneGame(self, piles):
        return True
```
```javascript [B4YhLudQ-JavaScript]
var stoneGame = function(piles) {
    return true;
};
```


**复杂度分析**

* 时间和空间复杂度：$O(1)$。