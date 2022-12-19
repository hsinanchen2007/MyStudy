### 解题思路
小白写法。非CS专业出身，考虑到的情况有限，不确定是否存在更特殊的情况，但是解决这题还是绰绰有余的。

首先将情况分为两大类，needle为字符串和空字符串。当needle为字符串时，又可以分为needle是否被haystack包含。

所以大致结构为：
1. 当needle!=''：
    - 如果needle被haystack包括，用haystack.index(needle)查找开始位置
    - 如果不被包括,返回-1
2. 当needle=='':
    - 返回0

以上结构可以用if+else的方式简化成以下:


### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle != '':
            if needle in haystack:
                return haystack.index(needle)
            else:
                return -1
        else:
            return 0

        
```