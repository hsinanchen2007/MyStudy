### 解题思路
将问题简化为一个递归问题：

- permute的终止条件：列表仅剩两个元素时，返回一个二维列表
- 每次permute做什么：分别将列表中的每一个元素作为开头元素，然后对剩下的元素执行permute，将开头元素和返回结果进行拼接
- 每个pernute返回什么：返回一个二维列表
### 代码

```python3
class Solution:
    def permute(self, nums):
        res = []
        if len(nums)==1:
            return [nums]
        if len(nums)==2:  #终止条件
            return [[nums[0],nums[1]],[nums[1],nums[0]]]
        for i in nums:
            temp = nums.copy()
            temp.remove(i) # 去除首位元素
            res = res + [[i] + r for r in self.permute(temp)] # 拼接
        return res
```
- 执行用时 :36 ms, 在所有 python3 提交中击败了99.18%的用户
- 内存消耗 :12.8 MB, 在所有 python3 提交中击败了99.37%的用户