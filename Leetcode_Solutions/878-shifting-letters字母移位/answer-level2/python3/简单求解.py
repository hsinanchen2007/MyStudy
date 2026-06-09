### 解题思路
1. 基于itertools库中accumulate函数，按照shifts逆序累加求和，比如[3,5,9] -> [17,8,9]
2. 分别转换即可

### 代码

```python3
from itertools import accumulate
class Solution:
    def shiftingLetters(self, S: str, shifts: List[int]) -> str:
        cussum = list(accumulate(shifts[::-1]))[::-1]
        ret = ''
        for i in range(len(shifts)):
            ret += chr((ord(S[i]) + cussum[i] - 97)%26 + 97)
        return ret
```