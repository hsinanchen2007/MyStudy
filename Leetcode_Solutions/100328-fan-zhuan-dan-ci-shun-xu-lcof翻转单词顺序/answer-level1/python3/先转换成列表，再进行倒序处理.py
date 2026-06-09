### 解题思路
用到了split,reverse,join函数
### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        list_s = s.split()
        list_s.reverse()
        s_reverse = " ".join(list_s)
        return s_reverse
```