### 解题思路
滑动窗口

### 代码

```python3
from collections import Counter
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        res = []
        pCounter=Counter(p)
        sCounter = Counter(s[:len(p)-1])
        for i in range(len(p)-1,len(s)):
            #include a new char in the window
            sCounter[s[i]] += 1 
            # This step is O(1),since there are at most 26 letters
            if sCounter == pCounter:
                res.append(i-(len(p)-1))
            # Decrease the count of oldest char in the window
            sCounter[s[i-(len(p)-1)]] -= 1
            if sCounter[s[i-(len(p)-1)]] == 0:
                del sCounter[s[i-(len(p)-1)]]
                
        return res
```