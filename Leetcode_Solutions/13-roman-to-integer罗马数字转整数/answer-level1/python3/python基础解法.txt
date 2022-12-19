### 解题思路
遍历整个数组，IV就是V-I，IIV就是V-I-I，VI就是V+I，所以就是当遍历的str的时候，当s[index]<s[index + 1]的时候减，大于的时候加。
### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        Roman2Int = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        Int = 0

        for index in range(len(s) - 1):
            if Roman2Int[s[index]] < Roman2Int[s[index + 1]]:
                Int -= Roman2Int[s[index]]
            else:
                Int += Roman2Int[s[index]]

        return Int + Roman2Int[s[-1]]
```