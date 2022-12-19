### 解题思路

1. 个人思路（比较繁琐）
- 先找到第一个非空字符串的位置，并判断它是否是数字或正负号，若不是则直接返回0，表示无法进行转换；
- 根据第一个非空字符的甄别，记录该字符串对应的整数的前缀---正号或负号；
- 判断完第一个非空字符之后，从非空字符的位置（或者是下一个位置）寻找尽可能多的连续数字字符，记作digits；
- 剔除digits的首部为0的字符，因为它对整数转换无益，且会因为位数的增加而影响之后的判断；
- 剔除之后，假若digits的长度大于最值的长度，则直接返回0；
- 若符合长度要求，则先将digits的长度填充至最值的长度，然后利用等长字符串的比较，判别大小；
- 最后，根据前缀及digits的内容输出即可；

内容上很繁琐，主要是各种细节考虑；


2. 参考思路
- [官方题解-有限状态自动机](https://leetcode-cn.com/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/)
- [官方题解-常规思路](https://leetcode-cn.com/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcod-2/)

还是自己基础太薄弱，考虑问题不够规范，逻辑性不强，再接再厉！

感谢！

### 代码

```python3
class Solution:
    def myAtoi(self, st: str) -> int:
        nums = len(st)
        i = 0
        flag = False
        while i < nums:
            if st[i] != ' ':
                if '0' <= st[i] <= '9' or st[i] == '-' or st[i] == '+':
                    flag = True
                break
            
            i += 1

        if not flag or i == nums:
            return 0

        if st[i] == '-':
            prex = -1
            i += 1
        elif st[i] == '+':
            prex = 1
            i += 1
        else:
            prex = 1
        
        digits = ''
        while i < nums and '0' <= st[i] <= '9':
            digits += st[i]
            i += 1
        
        if digits == '':
            return 0
        
        limit_min = 2147483648
        limit_max = 2147483647
        
        while digits:
            if digits[0] > '0':
                break
            digits = digits[1:]

        if len(digits) > 10:
            if prex > 0:
                return limit_max
            else:
                return prex*limit_min

        digits = digits.zfill(10)
        if digits > str(limit_max) and prex == 1:
            return limit_max
        elif digits > str(limit_min) and prex == -1:
            return prex*limit_min
        else:
            return int(digits) * prex




        
        

```