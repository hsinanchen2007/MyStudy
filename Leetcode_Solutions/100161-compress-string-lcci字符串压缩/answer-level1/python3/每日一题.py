### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if not S:
            return ""
        pre_s = S[0]
        count =1
        res = ""
        for i in range(1,len(S)):
            if S[i]==pre_s:
                count+=1
            else:
                res+=pre_s
                res+=str(count)
                pre_s = S[i]
                count=1
        res+=pre_s
        res+=str(count)
        if len(res)>=len(S):
            return S
        else:
            return res

```