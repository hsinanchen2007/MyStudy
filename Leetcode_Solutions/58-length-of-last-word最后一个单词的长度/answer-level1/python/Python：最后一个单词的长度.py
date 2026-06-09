### 解题思路
正则，字符串的我会尽量用正则，一般速度不会很慢，但是空间都不小

### 代码

```python3
import re
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        #return 0 if len(s)==0 or s==' ' else len(s.split( )[-1])
        obj=re.search(r'[\w]+',s[::-1])
        return obj.span()[1]-obj.span()[0] if obj else 0
```