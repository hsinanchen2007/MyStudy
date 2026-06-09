### 解题思路
[+-]?表示+,-其中之一，只能出现0次或1次；((\d+\.?\d*)|(\.\d+))，\d+\.?\d*匹配1234或26.或26.345，\.\d+匹配.1或.123；([eE][+-]?\d+)?，匹配指数，()?表示指数只能出现0次或1次，若有指数，则[eE]出现其中一个[+-]?出现一个或一个也没有，\d+表示指数，1或12

### 代码

```python3
class Solution:
    def isNumber(self, s: str) -> bool:
        pattern = r"^[+-]?((\d+\.?\d*)|(\.\d+))([eE][+-]?\d+)?$"
        return re.match(pattern, s.strip()) is not None
```