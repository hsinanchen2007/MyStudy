### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def hasGroupsSizeX(self, deck):
        """
        :type deck: List[int]
        :rtype: bool
        """
        def gcd(a, b):
            if a == 0:  return b
            return gcd(b%a, a)

        res = deck.count(deck[0])
        for i in set(deck):
            count = deck.count(i)
            if count < 2:   return False
            res = gcd(res, count)
            if res == 1:    return False
        return True
```