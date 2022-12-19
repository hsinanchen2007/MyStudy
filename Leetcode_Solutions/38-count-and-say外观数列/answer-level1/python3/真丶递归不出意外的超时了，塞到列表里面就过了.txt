首先说一下我的思路(可能是整复杂了)，大体思路肯定是递归，首先把前两项放进去，然后后面每项把前一项逐步切片转化为set集合，
set集合不会有重复的，所以如果它的长度不为一(由于是从[m:i+1]及[0:1]开始，所以长度一定大于零)，为2及说明到了变换的位置，
`f(n-1)[i]`即是变化的数，`s += str(i-m) + f(n-1)[i-1]`将前面数的个数及前面的数加入空字符串，令`m=i`重复此过程，一直
判断到剩最后全是相同的几个字符，即`0<m<len(f(n-1))`，然后将最后的个数+字符加入s中`s += str(len(f(n-1))-m) + f(n-1)[-1]`
还有一种情况，即前一项所有字符均相同(如f(2))，就直接写作`s += str(len(f(n-1))) + f(n-1)[0]`
以下是在本地编写的递归代码
```
def f(n):
    m = 0
    s = ''
    if n == 1:
        return '1'
    if n == 2:
        return '11'
    for i in range(len(f(n-1))):
        if len(set(f(n-1)[m:i+1])) != 1:
            s += str(i-m) + f(n-1)[i-1]
            m = i
    if 0<m<len(f(n-1)):
        s += str(len(f(n-1))-m) + f(n-1)[-1]
    if  m == 0:
        s += str(len(f(n-1))) + f(n-1)[0]
    return s
```
直接运用到本题上如下
```
class Solution:
    def countAndSay(self, n: int) -> str:
        m = 0
        s = ''
        if n == 1:
            return '1'
        if n == 2:
            return '11'
        for i in range(len(self.countAndSay(n-1))):
            if len(set(self.countAndSay(n-1)[m:i+1])) != 1:
                s += str(i-m) + self.countAndSay(n-1)[i-1]
                m = i
        if 0<m<len(self.countAndSay(n-1)):
            s += str(len(self.countAndSay(n-1))-m) + self.countAndSay(n-1)[-1]
        if  m == 0:
            s += str(len(self.countAndSay(n-1))) + self.countAndSay(n-1)[0]

        return s
```
测试到9的时候超时，后将每一项放入列表中，92ms通过
```
class Solution:
    def countAndSay(self, n: int) -> str:
        lis = ['1','11']
        for i in range(n-2):
            m = 0
            s = ''
            j = lis[-1]
            for t in range(len(j)):
                if len(set(j[m:t + 1])) != 1:
                    s += str(t-m) + j[t-1]
                    m = t
            if 0<m<len(j):
                s += str(len(j)-m) + j[-1]
            if  m == 0:
                s += str(len(j)) + j[0]
            lis.append(s)
        return lis[n-1]
```

`for i in range(n-2)`为要求的数的个数，相当于调用递归函数的次数。
