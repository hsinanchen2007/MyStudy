### 解题思路
注意为结果字符串res添加的条件，在循环结束后需要多一次添加。

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        res = ''
        n = len(S)
        if n == 0 or n == 1:
            return S
        i = 0
        num = S[i]
        count = 0
        while i < n:
            if S[i] == num:
                count += 1
                i += 1
            else:
                res += num
                res += str(count)
                count = 1
                num = S[i]
                i += 1
        res += num
        res += str(count)
        return res if len(res) < n else S
                
                
```