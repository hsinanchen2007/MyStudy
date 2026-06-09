#### 方法 1: 直接合并后排序
##### 算法

最直观的方法是先将数组 `B` 放进数组 `A` 的尾部，然后直接对整个数组进行排序。

```python [-Python]
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        A[m:] = B
        A.sort()
```
```cpp [-C++]
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        for (int i = 0; i != n; ++i)
            A[m + i] = B[i];
        sort(A.begin(), A.end());
    }
};
```

##### 复杂度分析
  * 时间复杂度：$O((m+n)\log(m+n))$
    排序序列长度为 $m+n$，套用快速排序的时间复杂度即可，平均情况为 $O((m+n)\log(m+n))$。

  * 空间复杂度：$O(\log(m+n))$
    排序序列长度为 $m+n$，套用快速排序的空间复杂度即可，平均情况为 $O(\log(m+n))$。

#### 方法 2: 双指针
##### 算法
方法 1 没有利用数组 `A` 与 `B` 已经被排序的性质。为了利用这一性质，我们可以使用双指针方法。这一方法将两个数组看作队列，每次从两个数组头部取出比较小的数字放到结果中。如下面的动画所示：

![lc_animation.gif](https://pic.leetcode-cn.com/fc6ffc0e15f9af4cfd24be0e5848b704d378236c658e46da21ef9264d924614b-lc_animation.gif){:width=540}

我们为两个数组分别设置一个指针 `pa` 与 `pb` 来作为队列的头部指针。代码实现如下：

```python [-Python]
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        sorted = []
        pa, pb = 0, 0
        while pa < m or pb < n:
            if pa == m:
                sorted.append(B[pb])
                pb += 1
            elif pb == n:
                sorted.append(A[pa])
                pa += 1
            elif A[pa] < B[pb]:
                sorted.append(A[pa])
                pa += 1
            else:
                sorted.append(B[pb])
                pb += 1
        A[:] = sorted
```
```cpp [-C++]
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int pa = 0, pb = 0;
        int sorted[m + n];
        int cur;
        while (pa < m || pb < n) {
            if (pa == m)
                cur = B[pb++];
            else if (pb == n)
                cur = A[pa++];
            else if (A[pa] < B[pb])
                cur = A[pa++];
            else
                cur = B[pb++];
            sorted[pa + pb - 1] = cur;
        }
        for (int i = 0; i != m + n; ++i)
            A[i] = sorted[i];
    }
};
```
##### 复杂度分析
  * 时间复杂度：$O(m+n)$
    指针移动单调递增，最多移动 $m+n$ 次，因此时间复杂度为 $O(m+n)$。

  * 空间复杂度：$O(m+n)$
    需要建立长度为 $m+n$ 的中间数组 `sorted`。

#### 方法3：逆向双指针
##### 算法
方法 2 中之所以要使用临时变量，是因为如果直接合并到数组 `A` 中，`A` 中的元素可能会在取出之前被覆盖。那么如何直接避免覆盖 `A` 中的元素呢？观察可知，`A` 的后半部分是空的，可以直接覆盖而不会影响结果。因此可以指针设置为从后向前遍历，每次取两者之中的较大者放进 `A` 的最后面。

严格来说，在此遍历过程中的任意一个时刻，`A` 数组中有 $m-pa-1$ 个元素被放入 `A` 的后半部，`B` 数组中有 $n-pb-1$ 个元素被放入 `A` 的后半部，而在指针 `pa` 的后面，`A` 数组有 $m+n-pa-1$ 个位置。由于

$$m+n-pa-1\geq m-pa-1+n-pb-1$$

等价于

$$pb\geq -1$$

永远成立，因此 `pa` 后面的位置永远足够容纳被插入的元素，不会产生 `pa` 的元素被覆盖的情况。

实现代码如下：

```python [-Python]
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        pa, pb = m - 1, n - 1
        tail = m + n - 1
        while pa >= 0 or pb >= 0:
            if pa == -1:
                A[tail] = B[pb]
                pb -= 1
            elif pb == -1:
                A[tail] = A[pa]
                pa -= 1
            elif A[pa] > B[pb]:
                A[tail] = A[pa]
                pa -= 1
            else:
                A[tail] = B[pb]
                pb -= 1
            tail -= 1
```
```cpp [-C++]
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int pa = m - 1, pb = n - 1;
        int tail = m + n - 1;
        int cur;
        while (pa >= 0 || pb >= 0) {
            if (pa == -1)
                cur = B[pb--];
            else if (pb == -1)
                cur = A[pa--];
            else if (A[pa] > B[pb])
                cur = A[pa--];
            else
                cur = B[pb--];
            A[tail--] = cur;
        }
    }
};
```

##### 复杂度分析
  * 时间复杂度：$O(m+n)$
    指针移动单调递减，最多移动 $m+n$ 次，因此时间复杂度为 $O(m+n)$。
  
  * 空间复杂度：$O(1)$
    直接对数组 `A` 原地修改，不需要额外空间。