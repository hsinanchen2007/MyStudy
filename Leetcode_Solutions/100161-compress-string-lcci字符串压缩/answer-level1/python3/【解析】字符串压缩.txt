### 解题思路
比较简单的字符串题目，只要照着题目的思路去做基本就可以。

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if S == "":
            return ""

        cur_str = ""
        cur_char = S[0]
        cnt = 1
        for i in range(1, len(S)):
            if S[i] == S[i-1]:
                cnt += 1
            else:
                cur_str += cur_char + str(cnt)
                cur_char = S[i]
                cnt = 1
        cur_str += cur_char + str(cnt)

        if len(cur_str) < len(S):
            return cur_str
        else:
            return S

```