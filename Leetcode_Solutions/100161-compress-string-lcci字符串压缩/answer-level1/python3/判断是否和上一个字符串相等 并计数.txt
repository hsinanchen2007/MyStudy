### 解题思路
判断是否和上一个字符串相等 并计数

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if S:
            checknum=0
            last=S[0]
            res=''
            for i in S:
                if i == last:
                    checknum+=1
                if i != last:
                    res+=f"{last}{checknum}"
                    checknum=1
                last=i
            res+=f"{last}{checknum}"
            if len(res)>=len(S):
                return S
            else:
                return res
        else:
            return S


```