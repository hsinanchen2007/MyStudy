### 解题思路
use counter
### 代码

```python
from collections import Counter
class Solution(object):
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        return [k for k, v in (Counter(A.split()) + Counter(B.split())).items() if v == 1]

```