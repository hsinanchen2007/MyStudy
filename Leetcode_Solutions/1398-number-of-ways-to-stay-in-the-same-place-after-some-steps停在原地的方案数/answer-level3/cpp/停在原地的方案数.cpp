### 方法一：动态规划
 
对于统计方案数类型的题目，常用的一种方法是动态规划（或递推）。

我们用 `f[i][j]` 表示在进行了 `i` 次操作后，指针位置为 `j` 的方案数。由于指针在每一步操作中可以从向左移动 `1` 步、停在原地、向右移动 `1` 步中选择一种，因此对于状态 `f[i][j]`，它可以从 `f[i - 1][j - 1]`，`f[i - 1][j]`，`f[i - 1][j + 1]` 这三个状态转移而来。这样我们就可以写出状态转移方程：

```
f[i][j] = f[i - 1][j - 1] + f[i - 1][j] + f[i - 1][j + 1]
f[0][0] = 1
```

在状态转移方程中需要注意边界情况。例如当 `j = 0` 时，`f[i - 1][j - 1]` 不是一个合法的状态。

在 `steps` 次操作后，指针位置为 `0` 的方案数即为 `f[steps][0]`，但上述方法的时间复杂度为 $O(\text{steps} * \text{arrLen})$，会超出时间限制，因此我们需要进行一些优化。注意到在 `steps` 次操作后，指针的位置其实并不会超过 `steps`，因此可以将数组的长度置为 `arrLen` 和 `steps + 1` 中的较小值，这样就减少了动态规划的时间复杂度。

```C++ [sol1]
class Solution {
private:
    static const int mod = 1000000007;
    
public:
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps + 1);
        vector<vector<int>> f(steps + 1, vector<int>(arrLen));
        f[0][0] = 1;
        for (int i = 1; i <= steps; ++i) {
            for (int j = 0; j < arrLen; ++j) {
                for (int k = -1; k <= 1; ++k) {
                    if (j - k >= 0 && j - k < arrLen) {
                        f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
                    }
                }
            }
        }
        return f[steps][0];
    }
};
```

```Python [sol1]
class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        arrLen = min(arrLen, steps + 1)
        f = [[0] * arrLen for _ in range(steps + 1)]
        f[0][0] = 1
        for i in range(1, steps + 1):
            for j in range(arrLen):
                for k in [-1, 0, 1]:
                    if 0 <= j - k < arrLen:
                        f[i][j] += f[i - 1][j - k]
        return f[steps][0] % (10**9 + 7)
```

**复杂度分析**

- 时间复杂度：$O(\text{steps} * \min (\text{arrLen}, \text{steps} + 1))$。

- 空间复杂度：$O(\text{steps} * \min (\text{arrLen}, \text{steps} + 1))$。


### 方法二：动态规划 + 空间优化

可以发现，在状态转移方程中，`f[i][j]` 只会从 `f[i - 1][..]` 即第 `i - 1` 行的三个状态转移而来。因此我们在进行动态规划时，只需要存储当前行 `i` 和上一行 `i - 1` 的状态。这样就减少了空间复杂度。

下面的代码中给出了两种常见的处理方法：

- 在 `C++` 代码中，我们使用一个两行的二维数组 `f`。当 `i` 为奇数时，`f[1]` 表示第 `i` 行的状态；当 `i` 为偶数时，`f[0]` 表示第 `i` 行的状态；

- 在 `Python` 代码中，我们使用两个一维数组 `f` 和 `g` 进行动态规划，其中 `f` 表示第 `i - 1` 行的状态，`g` 表示第 `i` 行的状态。

```C++ [sol2]
class Solution {
private:
    static const int mod = 1000000007;
    
public:
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps + 1);
        vector<vector<int>> f(2, vector<int>(steps + 1));
        f[0][0] = 1;
        for (int i = 1; i <= steps; ++i) {
            fill(f[i & 1].begin(), f[i & 1].end(), 0);
            for (int j = 0; j < arrLen; ++j) {
                for (int k = -1; k <= 1; ++k) {
                    if (j - k >= 0 && j - k < arrLen) {
                        f[i & 1][j] = (f[i & 1][j] + f[(i & 1) ^ 1][j - k]) % mod;
                    }
                }
            }
        }
        return f[steps & 1][0];
    }
};
```

```Python [sol2]
class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        arrLen = min(arrLen, steps + 1)
        f = [1] + [0] * (arrLen - 1)
        for i in range(1, steps + 1):
            g = [0] * arrLen
            for j in range(arrLen):
                for k in [-1, 0, 1]:
                    if 0 <= j - k < arrLen:
                        g[j] += f[j - k]
            f = g
        return f[0] % (10**9 + 7)
```

**复杂度分析**

- 时间复杂度：$O(\text{steps} * \min (\text{arrLen}, \text{steps} + 1))$。

- 空间复杂度：$O(\min (\text{arrLen}, \text{steps} + 1))$。