### 解题思路
纯暴力Python3解法
对nums进行类似与冒泡排序法进行循环，并且按照条件确定循环条件（如代码所示），最后返回一个列表。只不过运行时间太长。

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if nums[i]+nums[j]==target:
                    return [i,j]
```