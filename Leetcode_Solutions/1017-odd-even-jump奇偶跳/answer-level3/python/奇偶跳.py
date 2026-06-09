#### 方法一：单调栈

**思路**

首先，我们可以发现下一步应该跳到哪里只与我们当前的位置与跳跃次数的奇偶性有关系。

对于每一种状态，接下来可以跳到的状态一定只有一种（或者接下来不能跳跃了）。如果我们使用某种方法知道了不同状态之间的转移关系，我们就可以通过一次简单的遍历解决这个问题了。

于是，问题就简化为了：从索引 `i` 进行奇数次跳跃时，下一步应该跳到哪里去（如果有的话）。偶数次跳跃也是类似的。

**算法**

假设当前是奇数次跳跃，让我们来搞清楚在索引 `i` 的位置接下来应该跳到哪里去。

我们从小到大考虑数组 `A` 中的元素。假设当前我们正在考虑 `A[j] = v`，在我们已经处理过但是还未确定下一步跳跃位置的索引中（也就是 `<= v` 的那些）进行搜索。 如果我们找到了某些已经处理过的值 `v0 = A[i]` 且 `i < j`，那么我们就可以知道从索引 `i` 下一步应该跳跃到索引 `j` 的位置。

这种朴素的方法有一点点慢，然而我们可以使用一个很常见的技巧 `单调栈` 来加速这个过程。

我们在栈中保存所有已经处理过的索引 `i` ，并且时时刻刻维护这个栈中的元素是递减的。当我们增加一个新的索引 `j` 的时候，我们弹出栈顶比较小的索引 `i < j`，并且记录这些索引下一步全都会跳跃到索引 `j`。

然后，我们就知道所有的 `oddnext[i]`，也就是位于索引 `i` 在奇数次跳跃时将会跳到的位置。使用类似的方法，我们也可以求出 `evennext[i]`。有了这些信息，我们就可以使用动态规划的技巧快速建立所有可达状态。

```python [DWr7gh22-Python]
class Solution(object):
    def oddEvenJumps(self, A):
        N = len(A)

        def make(B):
            ans = [None] * N
            stack = []  # invariant: stack is decreasing
            for i in B:
                while stack and i > stack[-1]:
                    ans[stack.pop()] = i
                stack.append(i)
            return ans

        B = sorted(range(N), key = lambda i: A[i])
        oddnext = make(B)
        B.sort(key = lambda i: -A[i])
        evennext = make(B)

        odd = [False] * N
        even = [False] * N
        odd[N-1] = even[N-1] = True

        for i in xrange(N-2, -1, -1):
            if oddnext[i] is not None:
                odd[i] = even[oddnext[i]]
            if evennext[i] is not None:
                even[i] = odd[evennext[i]]

        return sum(odd)
```


**复杂度分析**

* 时间复杂度：$O(N \log N)$，其中 $N$ 是数组 `A` 的长度。

* 空间复杂度：$O(N)$。





---
#### 方法二： 树映射（Tree Map）

**思路**

在 *方法一* 中，原问题简化为：奇数次跳跃时，对于一些索引 `i`，下一步应该跳到哪里去（如果有的话）。

**算法**

我们可以使用 `TreeMap`，一个维护有序数据的绝佳数据结构。我们将索引 `i` 映射到 `v = A[i]` 上。

从 `i = N-2` 到 `i = 0` 的遍历过程中，对于 `v = A[i]`， 我们想知道比它略大一点和略小一点的元素是谁。  `TreeMap.lowerKey` 与 `TreeMap.higherKey` 函数就是用来做这样一件事情的。

了解这一点之后，解法接下来的内容就非常直接了： 我们使用动态规划来维护 `odd[i]` 和 `even[i]`：从索引 `i` 出发奇数次跳跃与偶数次跳跃是否能到达数组末尾。

```java [niMJSnZi-Java]
class Solution {
    public int oddEvenJumps(int[] A) {
        int N = A.length;
        if (N <= 1) return N;
        boolean[] odd = new boolean[N];
        boolean[] even = new boolean[N];
        odd[N-1] = even[N-1] = true;

        TreeMap<Integer, Integer> vals = new TreeMap();
        vals.put(A[N-1], N-1);
        for (int i = N-2; i >= 0; --i) {
            int v = A[i];
            if (vals.containsKey(v)) {
                odd[i] = even[vals.get(v)];
                even[i] = odd[vals.get(v)];
            } else {
                Integer lower = vals.lowerKey(v);
                Integer higher = vals.higherKey(v);

                if (lower != null)
                    even[i] = odd[vals.get(lower)];
                if (higher != null) {
                    odd[i] = even[vals.get(higher)];
                }
            }
            vals.put(v, i);
        }

        int ans = 0;
        for (boolean b: odd)
            if (b) ans++;
        return ans;
    }
}
```


**复杂度分析**

* 时间复杂度：$O(N \log N)$，其中 $N$ 是数组 `A` 的长度。

* 空间复杂度：$O(N)$。



