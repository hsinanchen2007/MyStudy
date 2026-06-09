### 解题思路
直接使用正则表达式，同时匹配两种模式
注意要使用re.search而不是re.match
match只匹配字符串开头

### 代码

```python3
class Solution:
    def checkRecord(self, s: str) -> bool:
        return not(re.search(r'A.*A|LLL', s))
```

