思路：创建一个字典，依次遍历数组，将数组中每一个元素作为键值，若字典中存在键值等于该元素减去different，则将该键的值+1作为当前键的值，若不存在，则将键值初始化为1

```
class Solution:
    def longestSubsequence(nums, different):
        num_dict = {}
        for c in nums:
            num_dict[c] = num_dict.get(c-different, 0) + 1
        return max(num_dict.values())
```
