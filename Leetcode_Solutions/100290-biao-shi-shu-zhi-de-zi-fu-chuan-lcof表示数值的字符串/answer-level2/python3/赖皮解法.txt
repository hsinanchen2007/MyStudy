### 解题思路

直接看看能不能转成数字，可以就说明是合法的。还有，题目中的`-1E-16`这个用例是*错误*的。

### 代码

```python3
class Solution:
    def isNumber(self, s: str) -> bool:
        try:
            float(s)
            return True
        except BaseException:
            return False 
```