```python
class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        maxNum = max(nums)
        def div(divider):
            if divider > maxNum: return len(nums) # 如果除数大于数组中每一个数， 那直接返回数组个数， 否则进行计算
            ans = 0
            for num in nums:
                ans += math.ceil(num / divider)
            return ans
        
        left, right = 1, maxNum # 左边界为1， 右边界为数组中最大的数
        ans = right
        while left < right: # 二分法
            mid = left + (right - left) // 2
            if div(mid) <= threshold: # 如果当前值小于等于threshold， 答案进行更新
                ans = min(ans, mid)
                right = mid
            else:
                left = mid + 1
        return ans
```
