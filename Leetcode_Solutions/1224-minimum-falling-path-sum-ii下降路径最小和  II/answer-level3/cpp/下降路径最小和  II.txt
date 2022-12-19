### 方法一：动态规划

我们可以使用动态规划来解决这个问题。

我们用 `f[i][j]` 表示从数组 `arr` 的前 `i` 行分别选择一个数字，并且第 `i` 行选择的数字为 `arr[i][j]` 时，可以得到的路径数字和的最小值。`f[i][j]` 可以从第 `i - 1` 行除了 `f[i - 1][j]` 之外的任意状态转移而来，这样我们可以写出如下的状态转移方程：

```
f[i][j] = min(f[i - 1][j']) + arr[i][j]    其中 j != j'
f[0][j] = arr[0][j]
```

这个动态规划的时间复杂度为 $O(N^3)$：我们需要使用三重循环分别枚举 `i`，`j` 和 `j0`。若使用 `C++` 语言实现该算法，则可以恰好在规定时间内通过所有测试数据，但对于 `Python` 语言则无法通过。因此我们必须对该算法进行优化。

我们注意到，状态转移方程中的 `min(f[i - 1][j'])` 在大多数情况下的值都是相同的。不妨记 `f[i - 1][jmin]` 是第 `i - 1` 行所有状态中的最小值，可以发现，在状态转移方程中：

- 如果 `j != jmin`，那么 `f[i][j]` 一定会从 `f[i - 1][jmin]` 转移而来，因为此时 `min(f[i - 1][j'])` 这一项可以取到最小值；

- 如果 `j == jmin`，那么 `f[i][j]` 不能从 `f[i - 1][jmin]` 转移而来，那么我们需要选择第 `i - 1` 行所有状态中的次小值，使得 `min(f[i - 1][j'])` 这一项取到最小值。

因此我们可以修改状态转移方程：

```
f[i][j] = f[i - 1][jmin[i - 1]] + arr[i][j]    其中 j != jmin[i - 1]
f[i][j] = f[i - 1][jnext[i - 1]] + arr[i][j]   其中 j == jmin[i - 1]
f[0][j] = arr[0][j]
```

其中 `jmin[i - 1]` 表示第 `i - 1` 行所有状态中最小值所在的位置，`jnext[i - 1]` 表示第 `i - 1` 行所有状态中次小值所在的位置，最小值和次小值可以相等。在计算完第 `i - 1` 行的所有状态之后，我们可以在 $O(N)$ 的时间得到 `jmin[i - 1]` 和 `jnext[i - 1]`，这样在计算第 `i` 行的状态时，我们不需要枚举原先的 `j0`，时间复杂度从 $O(N^2)$ 降低为 $O(N)$。因此总时间复杂度降低为 $O(N^2)$。

此外，我们还可以对空间复杂度进行优化。由于 `f[i][j]` 只会从 `f[i - 1][jmin[i - 1]]` 或 `f[i - 1][jnext[i - 1]]` 转移而来，那么我们并不用将第 `i - 1` 行的所有状态存储下来，而是可以浓缩成三个变量：

- `first_sum` 表示这一行的最小值；

- `first_pos` 表示这一行最小值对应的 `jmin`；

- `second_sum` 表示这一行的次小值。

状态转移方程修改为：

```Bash
f[i][j] = first_sum + arr[i][j]    其中 j != first_pos
f[i][j] = second_sum + arr[i][j]   其中 j == first_pos
```

通过这三个变量计算出第 `i` 行的所有状态之后，我们也不用将它们存储下来，同样可以浓缩成三个变量，为第 `i + 1` 行的动态规划提供转移基础。由于在计算第 `i + 1` 行的状态时，不需要第 `i - 1` 行的任何信息，因此第 `i - 1` 行浓缩成的三个变量此时可以被丢弃。这样以来，我们就将空间复杂度从 $O(N^2)$ 降低至了 $O(1)$。

```C++ [sol1-C++]
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int first_sum = 0, first_pos = -1, second_sum = 0;
        for (int i = 0; i < n; ++i) {
            int fs = INT_MAX, fp = -1, ss = INT_MAX;
            for (int j = 0; j < n; ++j) {
                int cur_sum = (first_pos != j ? first_sum : second_sum) + arr[i][j];
                if (cur_sum < fs) {
                    ss = fs;
                    fs = cur_sum;
                    fp = j;
                }
                else if (cur_sum < ss) {
                    ss = cur_sum;
                }
            }
            first_sum = fs;
            first_pos = fp;
            second_sum = ss;
        }
        return first_sum;
    }
};
```

```Python [sol1-Python3]
class Solution:
    def minFallingPathSum(self, arr: List[List[int]]) -> int:
        n = len(arr)
        first_sum, first_pos, second_sum = 0, -1, 0
        for i in range(n):
            fs, fp, ss = 10**9, -1, 10**9
            for j in range(n):
                cur_sum = (first_sum if first_pos != j else second_sum) + arr[i][j]
                if cur_sum < fs:
                    fs, fp, ss = cur_sum, j, fs
                elif cur_sum < ss:
                    ss = cur_sum
            first_sum, first_pos, second_sum = fs, fp, ss
        return first_sum
```

**复杂度分析**

- 时间复杂度：$O(N^2)$，其中 $N$ 是方阵 `arr` 的边长。

- 空间复杂度：$O(1)$。