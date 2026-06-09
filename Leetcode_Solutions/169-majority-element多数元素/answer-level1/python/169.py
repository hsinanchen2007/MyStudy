### 解题思路
1、先对list排序
2、遍历一遍新的list，记录每一个出现的数字的个数，遇到新的数字count=1，count>int(len(nums)/2)时输出

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        sort_nums = sorted(nums)
        count = 0
        for i in range(len(sort_nums)):
            count = count + 1
            if (i > 0) and (sort_nums[i] != sort_nums[i - 1]):
                count = 1
            if count > int(len(sort_nums) / 2):
                return sort_nums[i]
            
```