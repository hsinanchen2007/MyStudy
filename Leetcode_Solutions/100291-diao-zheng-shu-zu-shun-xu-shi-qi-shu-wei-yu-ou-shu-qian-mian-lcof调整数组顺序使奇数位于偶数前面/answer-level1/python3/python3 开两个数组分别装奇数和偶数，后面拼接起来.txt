```
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        odd_nums = []
        even_nums = []
        # 遍历原始数组
        for num in nums:
            if num % 2 == 0:
                even_nums.append(num)
            else:
                odd_nums.append(num)
        return odd_nums + even_nums
```
