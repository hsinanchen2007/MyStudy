**思路：**

考虑从`A`中的每个元素`A[i]`，如果求出包含`A[i]`并以`A[i]`为最小元素的所有子数组个数`n[i]`，则元素`A[i]`对答案`ans`的贡献为`n[i]*A[i]`，那么我们可以先求包含`A[i]`并以`A[i]`为最小元素的最长子数组，如果`A[i]`左边第一个小于`A[i]`的元素为`A[left]`，`A[i]`右边第一个小于`A[i]`的元素为`A[right]`，则包含`A[i]`并以`A[i]`为最小元素的最长子数组为`A[left+1:right]`，满足以`A[i]`为最小元素的所有子数组个数`n[i] = (i-left)*(right-i)`。我们用`left[i]`表示`A[i]`左边第一个小于`A[i]`元素的位置，用`right[i]`表示`A[i]`右边第一个小于`A[i]`元素的位置，`left`数组初始值为`-1`，`right`数组初始值为`len(A)`，求解`left`和`right`可以用单调栈来实现，可以两遍遍历，也可以一遍遍历，更优化的写法还可以一边遍历一边求解`ans`。

时间复杂度$O(N)$

空间复杂度$O(N)$

**图解：**

![图解](https://pic.leetcode-cn.com/95308677e2cb3f298cfe036c23f4d0c4564441f28decf2ea1a7246db01acf166.gif)

**代码：**

```python
class Solution:
    def sumSubarrayMins(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        len_A = len(A)
        if len_A == 0:
            return 0
        if len_A == 1:
            return A[0]
        
        ans = 0
        left = [0] * len_A
        right = [0] * len_A
        
        stack = []
        for i in range(len_A):
            while stack and A[stack[-1]] > A[i]:
                stack.pop()
            if not stack:
                left[i] = -1
            else:
                left[i] = stack[-1]
            stack.append(i)
        
        stack = []
        for i in range(len_A - 1, -1, -1):
            while stack and A[stack[-1]] >= A[i]:
                stack.pop()
            if not stack:
                right[i] = len_A
            else:
                right[i] = stack[-1]
            stack.append(i)
        
        for i in range(len_A):
            ans += (i - left[i]) * (right[i] - i) * A[i]
            ans %= 1000000007
        return ans
```

一遍遍历

```python
class Solution:
    def sumSubarrayMins(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        ans = 0
        A = [float('-inf')] + A + [float('-inf')]
        stack = []
        for i, a in enumerate(A):
            while stack and A[stack[-1]] > a:
                cur = stack.pop()
                ans += A[cur] * (i-cur) * (cur-stack[-1])
            stack.append(i)
        return ans % (10**9 + 7)
```