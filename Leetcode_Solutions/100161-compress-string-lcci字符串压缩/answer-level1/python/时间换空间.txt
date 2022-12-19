### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        # 循环
        if not S:
            return S
        res = S[0]
        du = 1
        for i in range(len(S)-1):
            if S[i] == S[i+1]:
                du += 1
            else:
                res += "{}{}".format(str(du), S[i+1])
                du = 1
        res += str(du)

        if len(res) >= len(S):
            res = S

        return res

```