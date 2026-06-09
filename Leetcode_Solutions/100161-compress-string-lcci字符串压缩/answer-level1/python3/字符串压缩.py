### 解题思路
遍历一遍， 字典记录出现次数，拼接新的字符串

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if len(S) <= 1:
            return S
        str_map = {}
        str_map[S[0]] = 1
        res = ""
        for i in range(1,len(S)):
            if i == len(S)-1:
                if S[i] not in str_map:
                    res += S[i-1] + str(str_map[S[i-1]]) + S[i] + str(1)
                else:
                    res += S[i] + str(str_map[S[i]] + 1)
            elif S[i] == S[i-1]:
                str_map[S[i]] += 1
            else:
                res += S[i-1] + str(str_map[S[i-1]])
                str_map = {}
                str_map[S[i]] = 1
        if len(res) >= len(S):
            return S
        else:
            return res

```