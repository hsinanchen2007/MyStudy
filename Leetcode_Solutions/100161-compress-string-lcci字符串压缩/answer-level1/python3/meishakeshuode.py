### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if not S:return ''
        sl = S +'#'
        ans = S[0]
        tmp = 1
        for i in range(1,len(sl)):
            if sl[i] != sl[i-1]:
                if sl[i] != '#':
                    ans += str(tmp)+sl[i];tmp  =1
                else:ans += str(tmp)
            else:tmp += 1
        if len(ans)>=len(S):return S
        else:return ans
```