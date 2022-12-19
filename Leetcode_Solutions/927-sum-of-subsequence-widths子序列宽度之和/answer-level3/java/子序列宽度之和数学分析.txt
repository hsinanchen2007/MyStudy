- 因为对于每一个非空子序列，只用关注其中的最大元素和最小元素，与序列的顺序无关，所以我们可以先对数组进行排序，方便处理。

- 用 `(i, j)` 表示固定两端的序列，它的最小值为 `a[i]`，最大值为 `a[j]`，这样的序列有 `2 ^ j - i - 1` 个。每个序列的宽度为 `a[j] - a[i]`，这一组序列的总宽度为 `(a[j] - a[i]) * (2 ^ j - i - 1)`。此时可以在 `O(n^2)` 的时间复杂度内解决问题。但是数据范围达到了 20000， `O(n^2)` 的算法不可取。要想办法降低时间复杂度。

- 对于以 `a[j]` 结尾的序列，它的总宽度为：

  `result = (a[j] - a[0]) * (2 ^ j - 1) + (a[j] - a[1]) * (2 ^ j - 2) + ... + (a[j] - a[j - 1]) * (2 ^ 0)`。

  可表示为 `result = X - Y`，其中 

  `X = a[j] * (2 ^ j - 1 + 2 ^ j - 2 + ... + 2 ^ 0) = a[j] * ((2 ^ j) - 1)`。

  `Y = a[0] * 2 ^ j - 1 + a[1] * 2 ^ j - 2 + ... + a[j - 1] * 2 ^ 0`。

- X 可以在常量时间内得到，Y 不行，但是可以知道 `Y[j + 1] = Y[j] * 2 + a[j]`。有了这个递推表达式，每个 Y 也可以在遍历过程中常数时间得到。

- 在计算过程中 res 可能为负，为了保证得到正确的结果，最后进行一次 `(res + MOD) % MOD`  这个操作，保证结果为正。

- 算法时间复杂度为 `O(nlogn)`，主要花费在排序上，排序完成后只需要 `O(n)` 的扫描。

```java
class Solution {
    public int sumSubseqWidths(int[] A) {
        final int MOD = (int) (1e9 + 7);
        Arrays.sort(A);
        int n = A.length;
        long res = 0;
        long p = 1;
        long sum = 0;
        for (int x : A) {
            res = (res + x * (p - 1) - sum) % MOD;
            p = (p << 1) % MOD;
            sum = (sum * 2 + x) % MOD;
        }
        return (int) ((res + MOD) % MOD);
    }
}
```

- 可以换一种思路，直接考虑以某个位置为端点的情况。

- 同样先对数组进行排序，方便处理。

- 在一个从小到大排序的数组中，有 `i` 个数小于 `A[i]`，有 `n - 1 - i` 个数大于 `A[i]`。

- 那么以 `A[i]` 为最大值的非空子序列有 `2 ^ i` 个。

- 那么以 `A[i]` 为最小值的非空子序列有 `2 ^ n - 1 - i` 个。

- 那么对于每一个 `A[i]`，它的贡献为 `A[i] * (2 ^ i) - A[i] * (2 ^ n - 1 - i)`。因为求的是最大元素和最小元素的差，作为最大值会采用加法，作为最小值会采用减法。

- 最终的结果就是 `sum{A[i] * (2 ^ i) - A[i] * (2 ^ n - 1 - i)}, 0 <= i < n`

  = `(A[0] * (2 ^ 0)) - (A[1] * (2 ^ 1)) + (A[i] * (2 ^ i)) - A[i] * (2 ^ n - 1 - i) + (A[n - 1 - i] * (2 ^ n - 1 - i)) - A[n - 1 - i] * (2 ^ i) + (A[n - 1] * (2 ^ n - 1)) - (A[n - 1] * (2 ^ 0)) `  

   = `sum{A[i] * (2 ^ i) - A[n - 1 - i] * (2 ^ i)}, 0 <= i < n`。

- 通过一次遍历，即可求出结果。

- 算法时间复杂度为 `O(nlogn)`，主要花费在排序上，排序完成后只需要 `O(n)` 的扫描。

```java
class Solution {
    public int sumSubseqWidths(int[] A) {
        final int MOD = (int) (1e9 + 7);
        Arrays.sort(A);
        int n = A.length;
        long res = 0;
        long p = 1;
        for (int i = 0; i < n; ++i) {
            res = (res + (A[i] - A[n - 1 - i]) * p) % MOD;
            p = (p << 1) % MOD;
        }
        return (int) ((res + MOD) % MOD);
    }
}
```
更多题解欢迎关注 [https://github.com/Jerring/LeetCode](https://github.com/Jerring/LeetCode) ^_^
