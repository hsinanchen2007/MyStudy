### 解题思路
1.首先判断字符串长度能否被整除
2.利用切词及集合长度
### 代码

```python3
import math
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        for x in range(1,len(s)//2+1):
            #判断能否整除
            if len(s)%x==0:
                if len(set(s.split(s[:x])))==1:
                    return True
        return False
```