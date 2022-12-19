### 解题思路
采用二分查找需找目标元素，找到目标元素后需要确认目标元素的左右区间是否还存在目标元素。
采用双指针分别在左右区间进行移动，直到找到值不等于目标元素的位置，最后返回左右区间的长度即可。

### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if len(nums) == 0:
            return 0
        l,r = 0, (len(nums) - 1)
        std = None
        while l < r:
            mid = (l + r + 1) >> 1
            if nums[mid] < target:
                l = mid
            elif nums[mid] > target:
                r = mid -1 
            else:
                std = mid
                break 
        else:
            if nums[l] == target:
                return 1
            else:
                 return 0
        ls = std 
        while ls > 0 :
            ls -=  1
            if nums[ls] != target:
                ls += 1
                break
        rs = std
        while rs < len(nums) - 1:
            rs += 1
            if nums[rs] != target:
                rs -= 1
                break
        return (rs - ls) + 1
        
```