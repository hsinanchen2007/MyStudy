
```python []
class Solution:
    def isStraight(self, nums: List[int]) -> bool:
        for i in range(1, 14):
            if i in nums:
                for j in range(i, i + 5):
                    if j in nums:
                        nums.remove(j)
                    elif 0 in nums:
                        nums.remove(0)
                    else:
                        return False
                break
        return True
```