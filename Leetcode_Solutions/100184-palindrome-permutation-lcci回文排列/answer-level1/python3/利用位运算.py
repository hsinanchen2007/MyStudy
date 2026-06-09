这道题除了统计，还可以参考之前的一道01.01 这题判断字符串有无重复字符
```
class Solution:
    def isPower(self, n):
        if n < 1:
            return False
        i = 1
        while i <= n:
            if i == n:
                return True
            i <<= 1
        return False


    def canPermutePalindrome(self, s: str) -> bool:
        mark = 0
        for char in s:
            movebit = ord(char)
            mark ^= 1<<movebit

        print(mark)
        
        return mark == 0 or self.isPower(mark)
```
isPower通过位运算来确定n是否为2的整数次幂
我们可以知道回文字符串要么只有一个字符是奇数，要么都是偶数
偶数次异或就是0，奇数次异或是1.
而且只有一个字符是奇数，那代表整个二进制表示只有一位是1，说明是2的整数次幂
如果都是偶数次，那么整个二进制表示都为0
所以最后判断就是针对这两种情况