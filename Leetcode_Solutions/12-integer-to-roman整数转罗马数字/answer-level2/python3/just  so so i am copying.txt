```
class Solution:
    def intToRoman(self, num: int) -> str:
        # 贪婪算法，从大遍历到小依次找出对应的罗马数字
        # 而倍数就是当前罗马数字的个数
        
        nums = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        romans = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]


        i = 0
        res = ''
        while num:
            if num // nums[i] > 0:
                d, num= divmod(num, nums[i])
                res += romans[i]*d 
            i += 1
        return res 
```
