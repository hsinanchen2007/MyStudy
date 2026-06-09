#### 方法：滑动窗口

**思路**

显然，我们只需要关注相邻两个数字之间的符号就可以了。  如果用 `-1, 0, 1` 代表比较符的话（分别对应 `<、 =、 >`），那么我们的目标就是在符号序列中找到一个最长的元素交替子序列 `1, -1, 1, -1, ...`（从 `1` 或者 `-1` 开始都可以）。

这些交替的比较符会形成若干个连续的块 。我们知道何时一个块会结束：当已经到符号序列末尾的时候或者当序列元素不再交替的时候。

举一个例子，假设给定数组为 `A = [9,4,2,10,7,8,8,1,9]`。那么符号序列就是 `[1,1,-1,1,-1,0,-1,1]`。它可以被划分成的块为  `[1], [1,-1,1,-1], [0], [-1,1]`。

**算法**

从左往右扫描这个数组，如果我们扫描到了一个块的末尾（不再交替或者符号序列已经结束），那么就记录下这个块的答案并将其作为一个候选答案，然后设置下一个元素（如果有的话）为下一个块的开头。

```java [bCXVkNbN-Java]
class Solution {
    public int maxTurbulenceSize(int[] A) {
        int N = A.length;
        int ans = 1;
        int anchor = 0;

        for (int i = 1; i < N; ++i) {
            int c = Integer.compare(A[i-1], A[i]);
            if (i == N-1 || c * Integer.compare(A[i], A[i+1]) != -1) {
                if (c != 0) ans = Math.max(ans, i - anchor + 1);
                anchor = i;
            }
        }

        return ans;
    }
}
```
```python [bCXVkNbN-Python]
class Solution(object):
    def maxTurbulenceSize(self, A):
        N = len(A)
        ans = 1
        anchor = 0

        for i in xrange(1, N):
            c = cmp(A[i-1], A[i])
            if i == N-1 or c * cmp(A[i], A[i+1]) != -1:
                if c != 0: 
                    ans = max(ans, i - anchor + 1)
                anchor = i
        return ans
```


**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是数组 `A` 的长度。
* 空间复杂度：$O(1)$。
  

  
