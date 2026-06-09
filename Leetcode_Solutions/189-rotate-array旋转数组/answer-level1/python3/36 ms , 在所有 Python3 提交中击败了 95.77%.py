### 解题思路
主要是in-plcae的改变. 

但实际上下面这个方法是O(n)复杂度
### 代码

```python3
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if not nums:
            return nums
        l = len(nums)
        index = k%l
        # nums = nums[l-index:l]+nums[:l-index] 这样不行,无法实现in-place的交换, 只是重新声明了一个地址nums[l-index:l]+nums[:l-index], 然后令num指向这个地址, num原本指向地址没有改动
        nums[:] = nums[l-index:l]+nums[:l-index]
```

这个更简洁, 用-倒序查找
```
nums[:] = nums[-k%len(nums): ] + nums[: -k%len(nums)]
```