
```python []
class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        xor, ans = 0, [0, 0]
        for num in nums:
            xor ^= num
        low = xor ^ (xor - 1) & xor
        for num in nums:
            ans[not num & low] ^= num
        return ans
```