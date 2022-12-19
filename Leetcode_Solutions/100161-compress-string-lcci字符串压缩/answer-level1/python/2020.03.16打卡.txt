### 解题思路
遍历字符串。

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if not S: return ''
        ans = S[0]
        s = -1
        lens = len(S)
        for i in range(0, lens - 1):
            if S[i+1] != S[i]:
                ans += str(i - s )+S[i + 1]
                s = i   
        ans += str(lens-1-s)      
        return ans if len(ans) < lens else S 

            



            

```