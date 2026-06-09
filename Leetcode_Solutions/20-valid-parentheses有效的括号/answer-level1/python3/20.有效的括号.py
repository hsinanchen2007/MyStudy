### 解题思路
判断整个（）、[]、{}，由内而外逐个删除

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        n=len(s)
        m=n%2
        aa = 0
        i=0
        if m!=0:
            return bool( )
        else:
            while i<len(s):
                if s.find('()')!=-1:
                    s=s.replace('()','')
                elif s.find('[]')!=-1:
                    s=s.replace('[]','')
                elif s.find('{}')!=-1:
                    s = s.replace('{}', '')
                # else:
                elif s=='':
                    return bool(1)
                else:
                    return bool( )
            return bool(1)







```