不是位运算的做法，但原理是一样的
```python3 []
class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        D, r = collections.defaultdict(set), n * 2
        for a, b in reservedSeats:
            if b != 1 and b != 10:
                D[a].add(b // 2)
        for d in D.values():
            r -= bool({1, 2} & d) + bool({3, 4} & d) - bool({1, 4} == d)
        return r
```
位运算的版本
```python3 []
class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        D, r = collections.defaultdict(int), n * 2
        for a, b in reservedSeats:
            if b != 1 and b != 10:
                D[a] |= 1 << (b // 2 - 1)
        for d in D.values():
            r -= bool(0b0011 & d) + bool(0b1100 & d) - bool(0b1001 == d)
        return r
```
