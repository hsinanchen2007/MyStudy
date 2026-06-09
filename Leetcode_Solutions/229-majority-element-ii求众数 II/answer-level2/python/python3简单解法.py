### 解题思路
为啥我这能打败99%的同学

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        ans = []
        l = len(nums)//3
        for num in set(nums):
            if nums.count(num) > l:
                ans.append(num)
        return ans
```