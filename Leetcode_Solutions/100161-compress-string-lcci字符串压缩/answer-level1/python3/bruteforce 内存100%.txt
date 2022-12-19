### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        n=len(S)
        if n < 2:
            return S
        num =1
        ans=''
        for i in range(1,n):
            if S[i-1] == S[i]:
                num+=1
                if i == n-1:
                    ans= ans+(S[i])+ str(num)
                    print(ans,S[i])
            else:
                ans= ans+(S[i-1])+ str(num)    
                num = 1  
                if i == n-1:
                    ans= ans+(S[i])+ str(num)
        if len(ans) >= n:
            return S
        else:
            return ans


        
```