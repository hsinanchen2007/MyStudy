### 解题思路
统计text中b,a,l,o,n的次数，其中l,o两个算一次，因为一个balloon单词里l,o各两个，
然后取短板，即次数最小值就是结果。

### 代码

```python3
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        return min(text.count('b'),text.count('a'),text.count('l')//2,text.count('o')//2,text.count('n'))
```