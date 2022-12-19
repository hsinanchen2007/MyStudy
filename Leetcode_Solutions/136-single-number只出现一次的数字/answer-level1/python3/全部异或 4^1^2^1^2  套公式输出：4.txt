### 解题思路
此处撰写解题思路
类别：位运算
方法：异或
每个人都把异或公式写了一遍，我就不重复了

如题：[4,1,2,1,2]
思路 4^1^2^1^2
根据 a^a = 0 , a^b^c = a^c^b
上面分解为  4^1^1^2^2
上面分解为  4^0^0 
输出 4

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result = nums[0]
        for i in range(1,len(nums)):
            result ^= nums[i]
        return result
```