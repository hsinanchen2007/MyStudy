### 解题思路
相当于分别提取处两个字符串，再将其前后调换即可，直观易理解。


### 代码

```python3
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        s_latter = ''.join(list(s)[n:])
        s_former = ''.join(list(s)[:n])
        return s_latter+s_former


```