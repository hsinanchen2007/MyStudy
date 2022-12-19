### 解题思路
既然已经知道是1~n了.那么可以先去掉重复元素求一次和，用nums的和减去它就是重复元素的值，用1~n的和减去它就是差的那个值

### 代码

```python3
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        #思路，那就找呗
        #用数学方法也可以直接找到答案
        sum_ = sum(set(nums))
        return [sum(nums) - sum_,sum(range(1,len(nums)+1)) - sum_]
```