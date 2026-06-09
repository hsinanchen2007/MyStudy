### 解题思路
其实也可以自己来实现 python 的 split 函数。


### 代码

```python3
class Solution:
    def countSegments(self, s: str) -> int:
        return len(s.split())
```