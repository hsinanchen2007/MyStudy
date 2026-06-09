#### 方法：滑动窗口

**思路**

方便起见，我们定义子数组：`(i,j) = [A[i], A[i+1], ..., A[j]]`，并且称一个子数组 *合法* 如果它包含 `K` 个不同的数字。

对于每一个 `j`，我们考虑包含所有 `i` 的集合 $S_j$，满足子数组 `(i, j)` 是合法的。

首先， $S_j$ 一定是一个连续的区间。如果 `i1 < i2 < i3` 且 `(i1,j)` 与 `(i3,j)`是合法的，但是 `(i2,j)` 不合法，这是矛盾的。因为 `(i2,j)` 一定包含超过 `K` 个不同的数字 [因为 `(i3,j)` 包含 `K` 个不同的数字]， 但是 `(i1,j)` [是 `(i2,j)` 的一个超集] 却只包含 `K` 个不同的数字。

所以，让我们将 $S_j​$ 写作区间： $S_j = [\text{left1}_j, \text{left2}_j]​$。

第二个结论是这些区间的端点一定是单调递增的 —— 也就是说 $\text{left1}_j$ 与 $\text{left2}_j$ 是单调递增的。与上相似的逻辑，我们也可以构造出这一结论的证明，思路是给现有子数组右端添加一个元素后，要么当前数组依旧合法，要么我们需要在左端删除一些元素使它保持合法。

**算法**

我们要维护两个滑动窗口以维护 $\text{left1}_j$ 与 $\text{left2}_j$。每一个滑动窗口能够计算窗口内有多少个不同的数字，并且支持像队列一样动态的增加 / 移除元素。

```java [zCoksB4a-Java]
class Solution {
    public int subarraysWithKDistinct(int[] A, int K) {
        Window window1 = new Window();
        Window window2 = new Window();
        int ans = 0, left1 = 0, left2 = 0;

        for (int right = 0; right < A.length; ++right) {
            int x = A[right];
            window1.add(x);
            window2.add(x);

            while (window1.different() > K)
                window1.remove(A[left1++]);
            while (window2.different() >= K)
                window2.remove(A[left2++]);

            ans += left2 - left1;
        }

        return ans;
    }
}

class Window {
    Map<Integer, Integer> count;
    int nonzero;

    Window() {
        count = new HashMap();
        nonzero = 0;
    }

    void add(int x) {
        count.put(x, count.getOrDefault(x, 0) + 1);
        if (count.get(x) == 1)
            nonzero++;
    }

    void remove(int x) {
        count.put(x, count.get(x) - 1);
        if (count.get(x) == 0)
            nonzero--;
    }

    int different() {
        return nonzero;
    }
}
```
```python [zCoksB4a-Python]
class Window:
    def __init__(self):
        self.count = collections.Counter()
        self.nonzero = 0

    def add(self, x):
        self.count[x] += 1
        if self.count[x] == 1:
            self.nonzero += 1

    def remove(self, x):
        self.count[x] -= 1
        if self.count[x] == 0:
            self.nonzero -= 1

class Solution(object):
    def subarraysWithKDistinct(self, A, K):
        window1 = Window()
        window2 = Window()
        ans = left1 = left2 = 0

        for right, x in enumerate(A):
            window1.add(x)
            window2.add(x)

            while window1.nonzero > K:
                window1.remove(A[left1])
                left1 += 1

            while window2.nonzero >= K:
                window2.remove(A[left2])
                left2 += 1

            ans += left2 - left1

        return ans
```


**复杂度分析**

* 时间复杂度：  $O(N)$，其中 $N$ 是数组 `A` 的大小。

* 空间复杂度：  $O(N)​$。



