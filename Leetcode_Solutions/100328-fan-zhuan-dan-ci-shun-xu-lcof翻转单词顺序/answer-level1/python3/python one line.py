### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(reversed(list(filter(lambda x:x!='',s.split(" ")))))
```
我承认要是面试写出这样的代码会被打死的