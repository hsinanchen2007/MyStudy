解法一：52ms
```python3
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        tmp = 0
        for i in J:
            tmp += S.count(i)
        return tmp
```
解法二：32ms
```python
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        tmp = 0
        for i in S:
            if i in J:
                tmp += 1
        return tmp
```
解法三：52ms，一行，同解法一
```python
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        return sum([S.count(i) for i in J])
```

