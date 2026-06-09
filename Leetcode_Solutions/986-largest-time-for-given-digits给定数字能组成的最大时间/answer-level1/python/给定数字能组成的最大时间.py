#### 方法一： 暴力

**思路**

遍历所有可能的时间，找到最大的那个。

**算法**

用 `(i, j, k, l)` 表示 `(0, 1, 2, 3)`，之后做全排列，对于每个排列，会有 `A[i]A[j] : A[k]A[l]`。

检查每个排列对应的时间是否合法，例如检查 `10*A[i] + A[j]` 是不是小于 `24` `10*A[k] + A[l]` 是不是小于 `60`。

最后把最大的有效时间输出就可以了。

**算法**

遍历这四个数字所有排列的可能，判断是不是一个合法的时间，如果合法且比目前存在的最大时间更大，就更新这个最大时间。

```java [solution1-Java]
// Solution inspired by @rock
class Solution {
    public String largestTimeFromDigits(int[] A) {
        int ans = -1;

        // Choose different indices i, j, k, l as a permutation of 0, 1, 2, 3
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j) if (j != i)
                for (int k = 0; k < 4; ++k) if (k != i && k != j) {
                    int l = 6 - i - j - k;

                    // For each permutation of A[i], read out the time and
                    // record the largest legal time.
                    int hours = 10 * A[i] + A[j];
                    int mins = 10 * A[k] + A[l];
                    if (hours < 24 && mins < 60)
                        ans = Math.max(ans, hours * 60 + mins);
                }

        return ans >= 0 ? String.format("%02d:%02d", ans / 60, ans % 60) : "";
    }
}
```

```python [solution1-Python]
class Solution(object):
    def largestTimeFromDigits(self, A):
        ans = -1
        for h1, h2, m1, m2 in itertools.permutations(A):
            hours = 10 * h1 + h2
            mins = 10 * m1 + m2
            time = 60 * hours + mins
            if 0 <= hours < 24 and 0 <= mins < 60 and time > ans:
                ans = time

        return "{:02}:{:02}".format(*divmod(ans, 60)) if ans >= 0 else ""
```

**复杂度分析**

* 时间复杂度： $O(1)$。

* 空间复杂度： $O(1)$。