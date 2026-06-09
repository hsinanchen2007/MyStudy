### 解题思路
此处撰写解题思路
![3.png](https://pic.leetcode-cn.com/885c07fbd1c7385c85c0deb43043de1136113aa6995c3f150766005879e59c3f-3.png)

### 代码

```python3
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        _debug = True
        if len(s1) + len(s2) != len(s3): return False
        self.buff = dict()
        return self._isInterleave(s1,0,s2,0,s3,0)

    def _isInterleave(self,s1:str,i:int,s2:str,j:int,s3:str,k:int)->bool:
        if k >= len(s3):
            return True
        if (i,j,k) in self.buff:
            return self.buff[(i,j,k)]
        ok = False
        if not ok and i < len(s1) and s1[i] == s3[k]:
            ok = self._isInterleave(s1,i+1,s2,j,s3,k+1)
        if not ok and j < len(s2) and s2[j] == s3[k]:
            ok = self._isInterleave(s1,i,s2,j+1,s3,k+1)
        self.buff[(i,j,k)] = ok
        return ok
```