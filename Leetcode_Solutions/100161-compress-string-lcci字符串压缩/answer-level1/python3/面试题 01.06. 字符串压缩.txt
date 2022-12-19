### 解题思路
双指针，一个记录重复开始的地方，一个记录结束的地方。注意最后需要将最后一个重复的数加入。其实可以避免，就是将记录重复的指针作为结束判断

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if not S:
            return S
        res = ""
        st = 0
        num = 0
        l = S[0]
        for i, v in enumerate(S):
            if l == v:
                continue
            else:
                num = i -st
                res+=l
                res+=str(num)
                l = v
                num = 0
                st = i
        res += l 
        res += str(len(S)-st)

        if len(res)>=len(S):
            return S
        else:
            return res

```