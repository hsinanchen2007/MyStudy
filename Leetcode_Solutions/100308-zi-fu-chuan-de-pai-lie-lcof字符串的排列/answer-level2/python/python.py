### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def permutation(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        res = []
        nums = list(s)
        def backtrack(nums, tmp):
            if not nums:
                res.append(''.join(tmp))
                return
            for i in range(len(nums)):
                backtrack(nums[:i] + nums[i + 1:], tmp + [nums[i]])
        backtrack(nums, [])
        return list(set(res))
```