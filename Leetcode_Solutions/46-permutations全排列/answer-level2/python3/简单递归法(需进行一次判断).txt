### 解题思路
采用递归的方式解题，保证输入的数组的【任一数字】与【剩余数字的全排列】分别组合后加入结果数组中。特别的，当输入长度为1的数组时需要直接输出结果。

### 代码

```python3
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums)==1:
            return [nums]
        res_l = []
        for num in nums:
            tem_l = nums.copy()
            tem_l.remove(num)
            for nums2 in self.permute(tem_l):
                res_l.append([num]+nums2)

        return res_l
```