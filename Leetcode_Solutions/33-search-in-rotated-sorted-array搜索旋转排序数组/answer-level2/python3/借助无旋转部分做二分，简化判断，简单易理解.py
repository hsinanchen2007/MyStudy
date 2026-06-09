### 解题思路
1. 先判断哪边没有旋转
2. 在没有旋转的部分做判断，如果target是否在其中，在则缩小范围为该部分，不在则缩小范围到另一部分
3. 当high low 长度为2的时候跳出循环（不需要做mid+1的复杂难懂的技巧跳出循环）
4. 比较high low 与target
5. 返回符合的值

### 代码

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low = 0
        high = len(nums)-1
        if not nums: return -1
        while low < high-1:
            mid = (low+high)//2
            # 左边无旋转
            if nums[low] < nums[mid]:
                if target <= nums[mid] and target >= nums[low]:
                    high = mid
                else:
                    low = mid
            # 右边无旋转
            else:
                if target <= nums[high] and target >= nums[mid]:
                    low = mid
                else:
                    high = mid
        if nums[low] == target: return low
        if nums[high] == target: return high
        return -1
```