执行用时 :48 ms, 在所有Python3提交中击败了95.22% 的用户。
内存消耗 :13.1 MB, 在所有Python3提交中击败了84.38%的用户。

基本思路，对于长度大于2的字符串，从第三个字符开始，当前位置可能的解码数只与前两位的解码数相关，因此只需用两个变量记录前两位的解码数即可。

代码略长，特殊情况做了单独考虑。
```
class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        if s[0] == '0':
            return 0  #0只能与前面的12结合，否则就不可能解码
        if n == 1:
            return 1
        res = []  #记录0出现的位置
        for i in range(n):
            if s[i] == '0':
                res.append(i)
        for i in res:
            if s[i-1] not in '12':  #判断0前面是否为1或2，不是则直接返回0
                return 0
        a = b =1  #记录当前考虑字符的前两位的解码数
        for i in range(1,n):
            p = int(s[i])*int(s[i-1])
            q = int(s[i-1:i+1])
            if p != 0 and q <= 26:  #只有当前字符和前一个字符均不为0，且当前字符与前一个字符组成的整数不大于26，到当前字符位置的解码数才是a+b
                a, b = b, a + b
            elif s[i] == '0':  #如果当前字符是'0'，则只能与前面的字符结合成一个，所以当前位置的解码数只能是其前面的a
                a, b = b, a
            else:
                a, b = b, b  #其他情况，当前位置的解码数是其前面相邻的b
        return b
```

代码简化一下：

```
class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        if s[0] == '0':
            return 0
        if n == 1:
            return 1
        a = b =1
        for i in range(1,n):
            if s[i] == '0' and s[i-1] not in '12':
                return 0
            q = int(s[i-1:i+1])
            if '0' not in s[i-1:i+1] and q <= 26:
                a, b = b, a + b
            elif s[i] == '0':
                a, b = b, a
            else:
                a, b = b, b
        return b```