```python
from collections import Counter
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        ans = Counter(A[0])
        for i in range(1, len(A)):
            ans &= Counter(A[i])
        return list(ans.elements())
```

思路：
使用Counter得到每个字符串的字典，字典相交，然后转换为list输出