### 解题思路
时间复杂度要求为0(n),想到了遍历一次数组

### 代码

```python3
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        fir_max, sec_max, thi_max = -1,-1,-1
        for i in range(len(nums)):
            if nums[i] > fir_max or fir_max == -1:
                fir_max, sec_max, thi_max = nums[i],fir_max,sec_max
            elif nums[i] < fir_max and (nums[i] > sec_max or sec_max == -1):
                sec_max, thi_max = nums[i], sec_max
            elif nums[i] < sec_max and (nums[i] > thi_max or thi_max == -1):
                thi_max = nums[i]
        return max(nums) if thi_max == -1 else thi_max
```