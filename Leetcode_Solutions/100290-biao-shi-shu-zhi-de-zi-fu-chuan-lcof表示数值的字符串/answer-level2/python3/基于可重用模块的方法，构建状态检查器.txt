### 解题思路

    1、状态迁移，弄了很久也没搞出来，最后用了最简单的分类思想

    2、检查可分成三类情况：整数、小数、指数

    3、其中指数 = 小数 + （e/E） + 整数

    4、主函数：
        去掉前后空格
        判断是否指数
            

    5、指数
        如果带e/E，则前后部分分别调用小数和整数处理 逻辑；
        否则，按小数处理

    5、整数：
        符号位处理
        0-9的计数cnt
        是否到达末尾且cnt>0

    6、小数：(兼容整数处理)
        符号位处理
        记录小数点之前0-9的个数begin
        跳过小数点
        记录小数点之后0-9的个数end
        是否到达末尾且begin+end>0


### 代码

```python3
class Solution:
    def checkInt(self, s):
        # XXXX
        i, n = 0, 0
        if i<len(s) and s[i] in '-+': i+=1
        S = set('0123456789')        
        while i<len(s) and s[i] in S:
            i, n = i+1, n+1
        #到达末尾，且n>0
        return i==len(s) and n>0

    def checkFloat(self, s):
        # XX.XXX   .XXX    XX.
        S = set('0123456789')
        i, begin, end = 0, 0, 0
        if i<len(s) and s[i] in '-+': i+=1
        
        while i < len(s) and s[i] in S:
            begin, i = begin+1, i+1
        if i<len(s) and s[i]=='.'[0]:
            i+=1
        while i < len(s) and s[i] in S:
            end, i = end+1, i+1
        #到达末尾，且begin+end>0
        return i==len(s) and begin+end>0

    def checkExp(self, s):
        for i in range(len(s)):
            if s[i] not in 'eE':continue
            #eE之前按小数处理，eE之后按整数处理
            return self.checkFloat(s[0:i]) and self.checkInt(s[i+1:])
        #直接按小数处理(兼容整数处理)
        return self.checkFloat(s)
        
    def delblank(self, s):
        i, e = 0, len(s)-1
        while i<e and(s[i]==' '[0] or s[e]==' '[0]):
            if s[i]==' '[0]: i+=1
            if s[e]==' '[0]: e-=1
        return s[i:e+1]

    def isNumber(self, s: str) -> bool:    
        return self.checkExp(self.delblank(s))

```