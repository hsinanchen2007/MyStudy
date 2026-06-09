### 解题思路
先通过`str.count()`计算出有多少space
再用`str.replace(old, new, number)`替换空格即可。

### 代码

```python3
class Solution:
    def replaceSpace(self, s: str) -> str:
        num_space = s.count(" ")
        return(s.replace(" ", "%20", num_space))
```