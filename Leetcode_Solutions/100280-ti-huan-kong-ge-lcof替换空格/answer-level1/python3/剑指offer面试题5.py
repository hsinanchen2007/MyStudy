### 解题思路
python选手一号卢本伟准备就绪

### 代码

```python3
class Solution:
    def replaceSpace(self, s: str) -> str:
        if len(s) < 0 or len(s) > 10000:
            return False
        else :
            return s.replace(' ','%20')
```