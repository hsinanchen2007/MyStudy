### 解题思路
对nums列表做异或求和（即模2求和），出现次数为偶数的数字会得0，只有出现次数为单数的数字会被留下来
```

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        a = 0
        for i in nums:
            a = a ^ i
        return a
