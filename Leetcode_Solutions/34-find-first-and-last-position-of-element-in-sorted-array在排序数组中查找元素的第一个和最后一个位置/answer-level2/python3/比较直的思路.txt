### 解题思路
二分查找，找到就跳出。
在找到的位置向前向后查找。
特殊情况特殊处理
[],[8],[8,8]

### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        if n == 1 and nums[0] == target: return [0,0]
        high = n-1
        low = 0
        i = -1
        while low < high:
            mid = (low + high)//2
            if target >= nums[low] and target <= nums[mid]:
                high = mid
            else:
                low = mid + 1
            if nums[low] == target:
                i = low
                break
            elif nums[high] == target:
                i = high
                break
        j = i
        if i == -1:
            return [-1,-1]
        while i < n and nums[i] == target:
            i = i+1
        while j > -1 and nums[j] == target:
            j = j-1
        return [j+1,i-1]

```