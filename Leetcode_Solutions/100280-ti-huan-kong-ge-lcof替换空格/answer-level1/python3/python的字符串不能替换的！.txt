### 解题思路
还不如就直接一行语句呢！速度还快8ms

### 代码

```python3
class Solution:
    def replaceSpace(self, s: str) -> str:
        # return s.replace(' ', '%20')
        res = [0] * len(s) * 3
        i = 0
        for s_ in s:
            if s_ != ' ':
                res[i] = s_
                i += 1
            else:
                res[i:i+3] = ['%', '2', '0']
                i += 3
        return ''.join(res[:i])

```