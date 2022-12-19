### 解题思路
在python中nums.index可以直接返回数组中第一个target索引， 那么我们的目标就是用二分法来找最后一个target
直接用例子说明思路:
假设nums = [5, 7, 7, 8, 8, 10]     target = 8
* 首先求出mid = 3; 8在nums[3:]
* mid = (3+6)//2; 8在nums[4:]
* mid = (4+6)//2; 8不在nums[5:],那么end = mid = 5
* nums[4:5]只有一个元素，返回该元素索引， 即4

### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if target not in nums:
            return [-1, -1]

        length = len(nums)
        res = []
        res.append(nums.index(target))
        start, end = 0, length

        # 二分结束条件，直到最后只剩有一个元素才跳出循环
        while len(nums[start:end])>=2:
            mid = (start + end)//2 
            if target in nums[mid:]:
                start = mid
            else:
                end = mid
        res.append(start)
        return res
```

实际上将代码稍微改动下，使用两次二分法分别查找首尾的target, 从而避免使用index方法，而总的时间复杂度依然是log(n)
```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if target not in nums:
            return [-1, -1]

        length = len(nums)
        res = []
        # res.append(nums.index(target))
        start, end = 0, length

        # 二分结束条件，直到最后只剩有一个元素才跳出循环
        while len(nums[start:end])>=2:
            mid = (start + end)//2 
            if target in nums[:mid]:
                end = mid
            else:
                start = mid
        res.append(start)

        start, end = 0, length
        while len(nums[start:end])>=2:
            mid = (start + end)//2 
            if target in nums[mid:]:
                start = mid
            else:
                end = mid
        res.append(start)
        return res
        

```