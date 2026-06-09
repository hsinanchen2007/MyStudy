### 解题思路
运用递归，当数组长度为1时，直接添加即可；
此外，需考虑函数跳出时，数组res需跳回，与调用函数前一致。

### 代码

```python3
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        lists = []
        res = []
        count = -1
        def mkgrp(nums,res,lists,count):
            lens = len(nums)
            count += 1
            if lens == 1:
                res.append(nums[0])
                lists.append(res)
                return
            for idx in range(lens):
                temp = nums.copy()
                res.append(temp.pop(idx))
                mkgrp(temp,res,lists,count)
                res = res[:count]                 
        mkgrp(nums,res,lists,count)
        return lists

                


```