### 解题思路
跟动态规划没什么关系吧？
利用迭代思想，假设只有1个元素，假设只有2个元素... 考虑到第四个就可以了。

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        l = len(nums)
        if l  == 0:
            return 0
        elif l == 1:
            return nums[0]
        elif l == 2:
            return max(nums)

        pre = nums[0]
        ret = max(nums[0], nums[1])

        for i in range(2, l):
            cur = max(ret, pre + nums[i])
            pre = ret
            ret = cur

        return ret
```