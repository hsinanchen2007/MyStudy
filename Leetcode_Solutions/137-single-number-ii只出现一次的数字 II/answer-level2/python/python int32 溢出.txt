```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        bit, result = 1, 0
        for _ in range(32):
            cnt = 0
            for num in nums:
                if bit & num == bit:
                    cnt += 1

            if cnt % 3:
                result |= bit

            bit <<= 1

        if result > 0x7fffffff:
            result -= 4294967296

        return result
```