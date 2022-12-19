### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        count=1
        res=""
        if len(S)<=1:
            return S
        for i in range(1,len(S)):
            if S[i]==S[i-1]:
                count+=1
            else:
                res+=(S[i-1]+str(count))
                count=1
            if i==len(S)-1:
                res+=(S[i]+str(count))
        if len(res)<len(S):
            return res
        else:
            return S
```