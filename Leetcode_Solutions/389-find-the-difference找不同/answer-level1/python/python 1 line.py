### 解题思路
此处撰写解题思路

### 代码

```python
from collections import Counter
class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """ 
        return list((Counter(t) - Counter(s)).keys())[0]

```