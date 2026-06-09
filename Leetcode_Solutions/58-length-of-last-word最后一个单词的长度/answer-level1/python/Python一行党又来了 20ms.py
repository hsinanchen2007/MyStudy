### 解题思路
切掉前后空格并分割 如果字符串长度为0则返回0 加这个是防止越界

### 代码

```python
class Solution(object):
    def lengthOfLastWord(self, s):
        return len(s.strip().split()[-1]) if len(s.strip()) > 0 else 0
```