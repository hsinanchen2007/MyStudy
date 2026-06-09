每次选择a，b，c里面最大的往返回字符串里加，注意处理边界情况
包括初始字符串。
如果最大字符串和最后一个字符相同，可能会产生aaa，于是选择第二大的往里加。
每次加了字符记得减相应个数。
```
class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        ret = ''
        while a>0 or b>0 or c>0:
            if a == max(a, b, c):
                if len(ret)==0 or ret[-1] != 'a':
                    if a>1:
                        ret += 'aa'
                        a-=2
                    else:
                        ret += 'a'
                        a-=1
                elif b>c:
                    ret += 'b'
                    b-=1
                elif c>0:
                    ret += 'c'
                    c-=1
                else:
                    break
            elif b == max(a, b, c):
                if len(ret)==0 or ret[-1] != 'b':
                    if b>1:
                        ret += 'bb'
                        b-=2
                    else:
                        ret += 'b'
                        b-=1
                elif a>c:
                    ret += 'a'
                    a-=1
                elif c>0:
                    ret += 'c'
                    c-=1
                else:
                    break
            elif c == max(a, b, c):
                if len(ret)==0 or ret[-1] != 'c':
                    if c>1:
                        ret += 'cc'
                        c-=2
                    else:
                        ret += 'c'
                        c-=1
                elif a>b:
                    ret += 'a'
                    a-=1
                elif b>0:
                    ret += 'b'
                    b-=1
                else:
                    break
        return ret
```
