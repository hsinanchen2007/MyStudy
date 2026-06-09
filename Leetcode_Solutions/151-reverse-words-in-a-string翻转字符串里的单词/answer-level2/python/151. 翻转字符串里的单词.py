### 解题思路
比较简洁的作法，全程调用Python库函数，但是不知道时间复杂度是多少。

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        # 先去掉两边的空格，然后分割字符串，再反转
        s.strip()
        res = s.split()
        res.reverse()
        return " ".join(res)
```