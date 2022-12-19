这里需要注意的就只有：
最后因为判定条件是有没有新的不同字母出现，所以最后出现的字母没有相比较的字母，需要我们手动自己加入


```
class Solution:
    def compressString(self, S: str) -> str:
        if not S:
            return ""

        res = ""
        cur = S[0]
        count = 1
        for i in range(1,len(S)):
            if cur == S[i]:
                count += 1
            else:
                res += cur+str(count)
                count = 1
                cur = S[i]

        res += cur + str(count)
        
        if len(res) >= len(S):
            return S
        else:
            return res
```
