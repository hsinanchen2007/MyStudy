利用 Python 的 collections 模块中的 Counter 类，可以统计每个字母出现次数

```Python
from collections import Counter


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)

```