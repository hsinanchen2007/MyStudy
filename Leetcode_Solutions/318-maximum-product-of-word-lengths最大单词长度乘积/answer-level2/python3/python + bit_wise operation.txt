```python
from functools import reduce
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        bit_arr = [reduce(lambda x, y: x | y, [1 << ord(c) - 97 for c in word], 0) for word in words]  
        res = 0
        for i in range(len(words) - 1):
            for j in range(i + 1, len(words)):
                if bit_arr[i] & bit_arr[j] == 0: 
                    res = max(res, len(words[i]) * len(words[j]))
        return res
```