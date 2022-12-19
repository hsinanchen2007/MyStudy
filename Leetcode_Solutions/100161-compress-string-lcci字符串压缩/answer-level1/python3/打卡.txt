### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if not S:
            return S
        res = S[0]
        count = 0
        for i in S:
            if i != res[-1]:
                res = res + str(count) + i
                count = 1
            else:
                count += 1
        res += str(count)
        return res if len(res) < len(S) else S


```