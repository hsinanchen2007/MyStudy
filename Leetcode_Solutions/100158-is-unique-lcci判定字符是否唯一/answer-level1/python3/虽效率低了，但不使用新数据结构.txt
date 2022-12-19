### 解题思路
隔一个抽取数据，判断连续的是否有可能相同

### 代码

```python3
class Solution:
    def isUnique(self, astr: str) -> bool:
        a = sorted(astr[::2])
        b = sorted(astr[1::2])
        for i in a:
            for j in b:
                if i == j:
                    return False
                else:
                    continue
        return True
```