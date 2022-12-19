### 解题思路
此处撰写解题思路
遇到了两个坑，一是在构建字符串a时，应该乘以-d，二是没有想到构建lambda函数是最简便的方法，故参考了大神的方案，使用lambda表达式。

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        d=len(a)-len(b)
        if d>0:
            b="".join(['0']*d)+b
        if d<0:
            a=''.join(['0']*-d)+a
        z=list(map(list,zip(a,b)))
        res=''
        tmp=0
        
        f=lambda x,y,z:int(x)+int(y)+int(z)               
        
        for i in range(len(z)-1,-1,-1):
            c=f(z[i][0],z[i][1],tmp)
            if c==0:res='0'+res;tmp=0
            elif c==1:res='1'+res;tmp=0
            elif c==2:res='0'+res;tmp=1
            elif c==3:res='1'+res;tmp=1
        return '1'+res if tmp else res

```