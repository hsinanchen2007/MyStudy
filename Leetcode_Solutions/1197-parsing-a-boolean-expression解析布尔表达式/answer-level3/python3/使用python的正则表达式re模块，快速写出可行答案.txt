**基本思路**：充分利用re模块，不断识别可化简部分，并替换到原有公式。
**解法优点**：   1 降低了出错可能性，节约了答题时间。
                2 方便Debug， 能够输出每个化简步骤的结果。
**缺点**： 程序的执行效率可能不够高


```python []
import re
from functools import reduce

def cacl(match):
    ope = match.group(1)
    s = match.group(2)
    space = {'t':True, 'f':False}
    if ope == '!':
        if not eval(s, space):
            return 't'
        return 'f'

    if ope == '&':
        if reduce(lambda a, b: a and b, (True if a =='t' else False for a in s.split(','))):
            return 't'
        return 'f'
    if ope == '|':
        if reduce(lambda a, b: a or b, (True if a =='t' else False for a in s.split(','))):
            return 't'
        return 'f'

class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        pat = re.compile(r'([!|&|\|])\(([tf,]+)\)')

        while pat.search(expression):
            print(expression)
            expression = pat.sub(cacl, expression)
            
        if expression == 't':
            return True
        return False
```

