```python
class Solution(object):
    def isAlienSorted(self, words, order):
        return words == sorted(words, key=lambda w: [order.index(x) for x in w])
```

