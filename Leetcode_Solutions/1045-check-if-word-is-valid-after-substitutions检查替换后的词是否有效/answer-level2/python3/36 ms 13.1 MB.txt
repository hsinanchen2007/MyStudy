### 解题思路
"abc"でSを繰返し分割する。
最後にSが空文字になったらTRUE
ならなかったらFALSE

### 代码

```python3
class Solution:
    def isValid(self, S: str) -> bool:
        while "abc" in S:
            partList = S.split("abc")
            S = "".join(partList)
        if S == "":
            return True
        return False
```