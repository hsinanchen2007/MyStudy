## 思路:

简单想法：对于题目是例子`[1, 2, 3, 4]`，想求出 `3`位置结果，我们要知道`3`位置前的乘积，和后面的乘积，即`[1, 2]` 和 `[4]`，所以我们用前缀积，和后缀积记录：

代码如下：

时间复杂度：$O(n)$

空间复杂度：$O(n)$

```python
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = [1]
        for num in nums[:-1]:
            prefix.append(prefix[-1] * num)
        suffix = [1]
        for num in nums[::-1][:-1]:
            suffix.append(suffix[-1] * num)
        return list([a * b for a, b in zip(prefix, suffix[::-1])])
```

我们可以优化空间 $O(1)$

```python
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n
        res[0] = 1
        for i in range(1, n):
            res[i] = res[i - 1] * nums[i - 1]
        right = 1
        for i in range(n - 1, -1, -1):
            res[i] *= right
            right *= nums[i]
        return res
```

