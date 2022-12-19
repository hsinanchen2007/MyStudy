``` python
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        # xor 为特殊两个数的异或
        xor = 0
        for num in nums:
            xor = xor ^ num
        # bit 为xor 第一个为1的位
        bit = 1
        while xor & bit == 0:
            bit <<= 1
        # 通过和bit异或的结果，把数分为两组，两个数肯定在不同组，两个组异或出的结果就是两个数
        a = 0
        b = 0
        for num in nums:
            if num & bit == 0:
                a ^= num
            else:
                b ^= num
        return [b,a]
```
