```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        f_dict = {}
        for num in nums:
            if num not in f_dict:
                f_dict[num] = 1
            else:
                f_dict[num] += 1
        return max(f_dict, key=f_dict.get)
```