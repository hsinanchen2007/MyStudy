```
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:return 0
        longest_array = 1
        num_set = set(nums)
        for num in num_set:
            if (num - 1) not in num_set:
                current_array = 1
                while num + 1 in num_set:
                    current_array += 1
                    num = num + 1
                    longest_array = max(longest_array, current_array)
        return longest_array
```
