思路清晰，直接遍历字符串。相同字母统计个数，最后再处理末尾字母。
```
class Solution:
    def compressString(self, S: str) -> str:
        res = ''
        count = 1
        if S == '':
            return ''
        for i in range(len(S)-1):
            if S[i] == S[i+1]:
                count += 1
            else:
                res += S[i]
                res += str(count)
                count = 1
        res += S[len(S)-1]
        res += str(count)
        if len(res) >= len(S):
            return S
        return res
```
