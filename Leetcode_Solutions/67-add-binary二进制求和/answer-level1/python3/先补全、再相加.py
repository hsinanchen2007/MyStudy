因为两个字符串的长度可能不相等，为同步结束，首先把短的string补全，在前面添加0的形式，然后再按位计算
```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        alist = list(a)
        blist = list(b)
        while len(alist)!=len(blist):
            if len(alist) > len(blist):
                blist.insert(0, 0)
            else:
                alist.insert(0, 0)
        target = 0
        i = len(alist) - 1
        reslist = []
        while i>=0:
            temp = int(alist[i]) + int(blist[i]) + target
            if temp <= 1:
                reslist.insert(0, str(temp))
                target = 0
            else:
                reslist.insert(0, str(temp - 2))
                target = 1
            i -= 1
        if target == 1:
            reslist.insert(0, str(target))
        return ''.join(reslist)
```