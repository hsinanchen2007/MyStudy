### 解题思路
此处撰写解题思路
一定要先判断数组长度为0和为1的特殊情况

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
        if len(nums) == 1:
            return nums[0]
        pre,cur = 0,0
        for num in nums:
            pre,cur = cur,max(pre+num,cur)
        return cur
```