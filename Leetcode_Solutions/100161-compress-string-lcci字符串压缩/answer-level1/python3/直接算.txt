### 解题思路
![image.png](https://pic.leetcode-cn.com/9b574d67d8a66058394d813d5cf0aca43a24b154d2b64b27293bc16505b84043-image.png)

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        r = ''
        temp = 1
        for s in S:
            if r == '':
                r += s
                continue
            if s == r[-1]:
                temp += 1
            else:
                r += str(temp)
                r += s
                temp = 1
        r += str(temp)
        if len(r) >= len(S):
            return S
        else:
            return r
```