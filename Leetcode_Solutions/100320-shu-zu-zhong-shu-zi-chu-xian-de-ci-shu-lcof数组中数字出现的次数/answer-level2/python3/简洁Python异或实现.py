### 代码

```python3
class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        eor = 0
        for num in nums:
            eor ^= num
        rightone = eor & (~eor + 1) # 提取最右边的1
        onlyone = 0
        for num in nums:
            if num & rightone != 0:
                onlyone ^= num
        return [onlyone, eor ^ onlyone]
```