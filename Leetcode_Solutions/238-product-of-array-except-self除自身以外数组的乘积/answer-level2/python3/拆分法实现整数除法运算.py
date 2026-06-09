计算所有元素乘积，使用拆分法实现整数除法运算

注意数组包含0的特殊情况
- 若有1个0，则0所在位置为其余数乘积
- 若有2个及以上的0，则数组所有乘积皆为0
```python3
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = 1
        non_zero_res = 1
        zeros = 0
        arr = [0 for i in range(n)]
        for i in range(n):
            if nums[i] == 0:
                zeros += 1
                res = 0
                if zeros > 1:
                    return arr
            else:
                non_zero_res *= nums[i]
                res *= nums[i]

        for i in range(n):
            if nums[i] != 0:
                arr[i] = self.div(res, nums[i])
            else:
                arr[i] = non_zero_res
        return arr

    def div(self, a, b):
        coef_a = 1
        coef_b = 1
        if a < 0:
            coef_a = -1
            a = -a
        if b < 0:
            coef_b = -1
            b = -b
        res = 0
        fac = 1 << 31
        while a > 0:
            if a >= b * fac:
                res += fac
                a -= b * fac
            fac >>= 1
        return coef_a * coef_b * res
```