### 解题思路
使用异或

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans=0
        for num in nums:
            ans ^= num
        return ans
```