####  方法一：记录索引
因为我们想知道 `N` 二进制下连续 `1` 之间的距离，所以我们记录 `1` 在二进制表示中的位置。例如，若 `N = 22 = 0b10110`。则我们会记下 `A = [1, 2, 4]`。则我们可以在数组中计算我们的答案。

**算法：**

在列表 `A` 中记录数字 `N` 二进制表示中 `1` 的位置。

要找到二进制表示中连续的 `1` 的最长距离，就是找到数组 `A` 中相邻元素差的最大值。

```python [solution1-Python]
class Solution(object):
    def binaryGap(self, N):
        A = [i for i in xrange(32) if (N >> i) & 1]
        if len(A) < 2: return 0
        return max(A[i+1] - A[i] for i in xrange(len(A) - 1))
```

```java [solution1-Java]
class Solution {
    public int binaryGap(int N) {
        int[] A = new int[32];
        int t = 0;
        for (int i = 0; i < 32; ++i)
            if (((N >> i) & 1) != 0)
                A[t++] = i;

        int ans = 0;
        for (int i = 0; i < t - 1; ++i)
            ans = Math.max(ans, A[i+1] - A[i]);
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(\log N)$。
* 空间复杂度：$O(\log N)$，数组 `A` 所使用的空间。



####  方法二：一次遍历
在方法一中我们用数组 `A` 记录了数字 `N` 二进制表示中的 `1` 的位置。

因为我们只关心连续的 `1`，因此我们不需要存储整个数组。只需要记住前一个 `1` 的位置。

**算法：**

我们用 `last` 存储上一个 `1` 的位置。如果数字 `N` 在第 `i` 个位置为 `1`，则我们的候选答案为 `i - last`，然后更新 `last = i`。

```python [solution2-Python]
class Solution(object):
    def binaryGap(self, N):
        last = None
        ans = 0
        for i in xrange(32):
            if (N >> i) & 1:
                if last is not None:
                    ans = max(ans, i - last)
                last = i
        return ans
```

```java [solution2-Java]
class Solution {
    public int binaryGap(int N) {
        int last = -1, ans = 0;
        for (int i = 0; i < 32; ++i)
            if (((N >> i) & 1) > 0) {
                if (last >= 0)
                    ans = Math.max(ans, i - last);
                last = i;
            }

        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(\log N)$。
* 空间复杂度：$O(1)$。