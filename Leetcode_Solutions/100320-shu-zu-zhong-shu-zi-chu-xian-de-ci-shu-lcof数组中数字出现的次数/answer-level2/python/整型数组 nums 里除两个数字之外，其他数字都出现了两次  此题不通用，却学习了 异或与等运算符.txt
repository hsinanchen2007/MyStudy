### 解题思路
1. 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)
    - 1）整型数组   ； 2） 仅两个数字出现一次(奇数次即可)；  3）其它均出现两次（偶数次即可）
    - 若不要求空间O(1)，其实可以采用dict 或 sorted 

2. [Python 运算符](https://www.runoob.com/python/python-operators.html)
    - ** 次方；  / 除法（py3 的结果可出浮点数）； // 取整除 - 返回商的整数部分（向下取整）
    - & 按位与(a^a=全1； a^全1=a; )；  ^ 按位异或运 (a^0=a; a^a=0)；  << 左移； >> 右移

### 代码

```python3
class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        nsize = len(nums)
        if nsize < 1:
            return None
        
        # all nums ^
        xor = 0
        for num in nums:
            xor ^= num 
        
        # find 1 bit from xor, and this bit can split this two target nums
        mask = 1
        while (xor & mask == 0):
            mask <<= 1
        
        res = [0, 0]
        for num in nums:
            if num & mask == 0:
                res[0] ^= num 
            else:
                res[1] ^= num 
        
        return res 
        
```