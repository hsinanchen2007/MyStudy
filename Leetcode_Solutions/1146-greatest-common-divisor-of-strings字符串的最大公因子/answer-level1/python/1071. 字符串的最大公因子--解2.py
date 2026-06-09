### 解题思路
此处撰写解题思路

### 代码

```python3
import math
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        lenc = math.gcd(len(str1), len(str2))
        strc = str1[:lenc]
        if strc * (len(str1)//lenc) == str1 and strc * (len(str2)//lenc) == str2:
            return strc
        return ''

```