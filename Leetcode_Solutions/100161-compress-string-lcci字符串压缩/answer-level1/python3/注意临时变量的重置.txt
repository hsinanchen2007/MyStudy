### 解题思路

增加哨兵，减少对最后一个字符为单个情况的单独分析。
注意次数t每次到新字符的时候需要重置，考虑临时变量的生存期


### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        s=''
        D=S+'0'
        t=1
        for i in range(0,len(D)-1):
            if D[i]==D[i+1]:
                t=t+1
            else:
                s+=D[i]+str(t)
                t=1
        if len(s)<len(S) and len(S)!=0:
             return s
        else:
            return S
```