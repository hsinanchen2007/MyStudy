## 解题思路
只需遍历一遍列表，同时维护两个值： __最小值__ 和 __次小值__ 。首先将两个值都定义为超大的数字，先判断最小值，因为最小值必须保持在次小值之前，再判断次小值，若在最小值和次小值之间，则更新次小值，若大于次小值，则满足条件。

**注：** 会发现一个问题，若出现有一个位于次小值之后的值比最小值还小，那么更新后是否就违背了“次小值必须出现在最小值之后”。事实上，这并不影响最后的结果，因为若后面出现了大于次小值的数字，则与更新前的“最小值-次小值-当前值”构成三元子序列。这里更新最小值只是为了获得更小的“最小值-次小值”二元子序列而不放过可能的结果。
## 代码
`Python 3.6`
`40 ms`
`13.4 MB`
```py
class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        length = len(nums)
        if length < 3:
            return False
        min_num, mid_num = 0xffffffff, 0xffffffff
        for i in range(length):
            num_i = nums[i]
            if num_i <= min_num:
                min_num = num_i
            elif num_i <= mid_num:
                mid_num = num_i
            else:
                return True
        return False
```