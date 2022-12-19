### 解题思路
由于不能使用额外内存，时间复杂度也有要求，因此考虑位运算。其他元素只出现两次，因此通过异或运算将元素的影响消除掉，剩下的就是只出现一次的元素。

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result = 0
        for i in range(len(nums)):
            result = result ^ nums[i]
        return result
```