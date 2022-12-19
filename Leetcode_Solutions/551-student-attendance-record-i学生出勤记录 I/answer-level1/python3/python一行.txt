```
class Solution:
    def checkRecord(self, s: str) -> bool:

        return not(len(s.split('A'))>2 or "LLL" in s)
```


执行用时 :48 ms, 在所有 Python3 提交中击败了71.99%的用户
内存消耗 :13.7 MB, 在所有 Python3 提交中击败了6.43%的用户