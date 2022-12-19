### 解题思路
- 我要解决什么问题？
- 我要解决的问题
1. 在不在这个数组中
    1.1 在这个数组中，index返回suoyin
    1.2 不在这个数组中：
        1.2.1 判断是在最左还是最右
        1.2.2 遍历找到该插入的位置
### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target in nums :
            return nums.index(target)
        else:
            if target >= nums[len(nums)-1] :
                return len(nums)
            elif target <= nums[0] :
                return 0
            else:
                for i in range(len(nums)):
                    if nums[i] > target:
                        return i
```