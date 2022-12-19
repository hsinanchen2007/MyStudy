### 解题思路
排序之后，如果这个这一位之前走过了，那么就跳过

### 代码

```python3
class Solution:
    def permuteUnique(self, nums: [int]) -> [[int]]:
        res = []
        # 出来的答案还是需要去重，在这还是考虑先排序
        nums.sort()

        def helper(nums_in, res_in):
            if nums_in == []:
                res.append(res_in)
            else:
                for i in range(len(nums_in)):
                    if i == 0 or (i > 0 and nums_in[i] != nums_in[i- 1]):
                        if i + 1 <= len(nums_in) - 1:
                            helper(nums_in[:i] + nums_in[i + 1:], res_in + [nums_in[i]])
                        else:
                            helper(nums_in[:i], res_in + [nums_in[i]])
        helper(nums, [])
        return res
```