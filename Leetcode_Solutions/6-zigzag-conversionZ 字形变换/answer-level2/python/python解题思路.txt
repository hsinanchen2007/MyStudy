### 解题思路
此处撰写解题思路

复制成二维数组直观理解
### 代码

```python3
class Solution:
    def convert(self, s: str, n: int) -> str:
        if n<=1:
            return s
        p=[]
        for i in range(n):
            p.append(s)
        h,l = 0,0
        o = [[] for i in range(n)]
        fi=1
        while h<len(s):
                o[l].append(p[l][h])
                l+=fi
                h+=1
                if l==0 or l==n-1:
                    fi*=-1

        u = ''
        for i in o:
            s = ''.join(i)
            u=u+s     
        return u
            
```