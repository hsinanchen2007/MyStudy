### 解题思路
将数组转成numpy矩阵，使用numpy的广播机制进行运算，再进行展开，不过只是提供一种思路，不知道为什么速度和内存都占的很大

### 代码

```python3
import numpy as np
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        m = {
            '2': list('abc'),
            '3': list('def'),
            '4': list('ghi'),
            '5': list('jkl'),
            '6': list('mno'),
            '7': list('pqrs'),
            '8': list('tuv'),
            '9': list('wxyz'),
            }
        if len(digits) == 0:
            return []
        res = np.char.array([''])
        for i in digits:
            tmp = np.char.array(m[i])
            tmp = tmp.reshape(len(tmp),1)
            res = (res + tmp).T.flatten()
        return res.tolist()
```