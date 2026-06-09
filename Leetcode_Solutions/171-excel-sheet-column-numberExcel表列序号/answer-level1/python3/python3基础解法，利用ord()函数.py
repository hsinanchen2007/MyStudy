#思路：本题实际上是一个26进制的数字化为十进制的问题，按照数字的习惯，先把给定的字符串反转，再将A~Z利用ord()函数对应到具体数字，比如ord('A')=65，而在题目中A代表1，所以每个字母的换算公式为ord(i) - 64，而每一位上的权重为26的i次方，所以依次累加每一位的十进制数量即可
```
class Solution:
    def titleToNumber(self, s: str) -> int:
        output = 0
        for i in range(len(s)):     
            output += pow(26, i) * (ord(s[::-1][i]) - 64)
        return output
```