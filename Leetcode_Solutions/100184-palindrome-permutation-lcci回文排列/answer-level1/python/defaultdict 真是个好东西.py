### 代码
```python
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        dic = collections.defaultdict(int)
        for char in s:
            dic[char]+=1
        odd,even = 0,0
        for v in dic.values():
            if v%2==0:even += 1
            else:odd += 1
        return True if odd <= 1 else False
```