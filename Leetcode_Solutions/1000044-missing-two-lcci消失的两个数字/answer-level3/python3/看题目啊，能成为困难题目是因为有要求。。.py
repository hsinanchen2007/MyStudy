```
class Solution:
    def missingTwo(self, nums: List[int]) -> List[int]:
        total_real = sum(nums)
        l = len(nums) + 2
        total_n = l * (l + 1) / 2
        ab_sum = total_n - total_real
        mul = 1
        for i in range(1, l + 1):
            mul *= i
        mul_real = 1
        for num in nums:
            mul_real *= num
        ab_square_sum = mul / mul_real
        a = int((ab_sum - (ab_sum ** 2 - 4 * ab_square_sum) ** 0.5) // 2)
        b = int((ab_sum + (ab_sum ** 2 - 4 * ab_square_sum) ** 0.5) // 2)
        return [a, b]
```
数学解法