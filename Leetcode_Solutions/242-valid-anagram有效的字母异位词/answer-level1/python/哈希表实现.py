### 解题思路

### 代码

```python3
class Solution:
    def make(self,m):
        res={}
        for i in range(len(m)):
            if m[i] in res.keys():
                res[m[i]]+=1
            else:
                res[m[i]]=1
        return res
    def isAnagram(self, s: str, t: str) -> bool:
        l1=self.make(s)
        l2=self.make(t)
        if l1==l2:
            return True
        else:
            return False
            
```