### 解题思路
re 正则匹配思路

### 代码

```python3
class Solution:
    def decodeString(self, s: str) -> str:
        import re
        pattern = re.compile(r'(\d+)\[(\w+)\]')
        m = pattern.findall(s) 
        while m:
            for num_of_copy, copy_char in m:
                s = s.replace('{}[{}]'.format(num_of_copy, copy_char), copy_char * int(num_of_copy))
            m = pattern.findall(s)
        return s
```