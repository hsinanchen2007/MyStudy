**思路：**

用`left[i]`来表示`i`左边的最大值（包括`i`），用`right[i]`来表示`i`右边的最小值（包括`i`），那么我们只需要寻找一个最小的`i`，使得`left[i]<=right[i+1]`。也有更简单的方法，用一次遍历，遍历到`i`时，当前答案为`ans`，则`ans`初始值为`1`。当我们从第二个元素开始遍历到第`i`个元素时，我们可以记录`[0,ans-1]`中最大元素为`leftMax`，记录`[ans, i]`中最大元素为`rightMax`，当`A[i]<leftMax`时，证明之前的分割不合理，需要更新分割为`ans = i + 1`。

时间复杂度$O(N)$

空间复杂度$O(N)$

**代码：**

两次遍历

```python
class Solution:
    def partitionDisjoint(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        l = len(A)
        left = [A[0]] * l
        right = [[A[l - 1]]] * l
        left_max = 0
        right_min = 1000000
        for i in range(l):
            left_max = max(left_max, A[i])
            left[i] = left_max
            right_min = min(right_min, A[l - i - 1])
            right[l - i - 1] = right_min
        for i in range(l - 1):
            if left[i] <= right[i + 1]:
                return i + 1
```

一次遍历

```python
class Solution:
    def partitionDisjoint(self, A):
        """
        :type A: List[int]
        :rtype: int
        """

        leftMax, rightMax = A[0], A[0]
        ans, n = 1, len(A)

        for i in range(1, n-1):
            if A[i] < leftMax:  
                ans = i + 1  # 更新分割线
                if rightMax > leftMax:
                    leftMax = rightMax
            elif A[i] > rightMax:
                rightMax = A[i]

        return ans
```