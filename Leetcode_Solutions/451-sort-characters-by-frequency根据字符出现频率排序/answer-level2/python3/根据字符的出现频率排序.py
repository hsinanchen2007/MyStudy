### 解题思路

say `s` = "tree"
* step1: build hashmap {character: frequency}, `dic` = {'t':1, 'r':1, 'e':2}
* step2: store characters in a bucket, where `bucket[i]` contains all characters of frequency `i`. `bucket` = ["","tr","ee"]
* step3: reverse traverse bucket to get the result. `res` = "eetr"

### 代码

```python []
from collections import Counter
class Solution:
    def frequencySort(self, s: str) -> str:
        dic = dict(Counter(s))
        bucket = [""] * len(s)
        for c, f in dic.items():
            bucket[f-1] += c * f
        res = ""
        for i in range(len(s)-1, -1, -1):
            res += bucket[i]
        return res
```