解题思路 利用有正则表达式功能的re模块，"."在正则表达式中代表除换行符外任意字符，所以用反斜杠转义。
```
import re
class Solution:
    def defangIPaddr(self, address: str) -> str:
        return re.sub('\.','[.]',address)
```
