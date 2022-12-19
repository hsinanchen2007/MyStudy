### 解题思路
直接匹配字符，倒序输出

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(re.findall(r'\S+',s)[::-1])        
```