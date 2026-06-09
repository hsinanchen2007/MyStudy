### 解题思路
用一次遍历获取压缩字符串

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if len(S)==0 :
            return ""
        
        ans = ""
        prev = S[0]
        num = 0
        for i in range(len(S)):
            if S[i] == prev:
                num += 1
            else:
                ans += (prev + str(num))
                num = 1
                prev = S[i]
        
        ans += (prev + str(num))
        
        if len(ans) >= len(S):
            return S
        else:
            return ans
            
```