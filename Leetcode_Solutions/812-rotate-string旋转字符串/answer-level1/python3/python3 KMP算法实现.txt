### 解题思路
使用KMP算法判断 B 是不是 A+A 的子串
时间复杂度：O(A+B)
空间复杂度：O(B)

### 代码

```python3
class Solution:
    def rotateString(self, A: str, B: str) -> bool:
        return len(A)==len(B) and (len(A)==0 or self.issubstr(A+A,B))

    def getnext(self,s):
        nex=[0]*(len(s)+1)
        nex[0]=-1
        i=0
        j=-1
        while i < len(s):
            if j==-1 or s[i]==s[j]:
                i+=1
                j+=1
                nex[i]=j
            else:
                j=nex[j]
        return nex

    def issubstr(self,a,b):
        nex=self.getnext(b)
        i=0
        j=0
        while i < len(a):
            if j==-1 or a[i]==b[j]:
                i+=1
                j+=1
                if j==len(b):
                    return True
            else:
                j=nex[j]
        return False
```