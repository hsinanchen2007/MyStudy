从a = [2, 13, 3, 11, 5, 17, 7]到b = [2, 3, 5, 7, 11, 13, 17]的步骤是:
1. 先从a头部拿一个数出来，从尾部添加到b中；
2. 然后从a头部拿一个数，添加到a的末尾。

先在逆转过来：
1. 先从b尾部拿一个数，添加到a头部；
2. 从a尾部拿一个数，添加到a头部。

所以我们一开始把数列排序好，就可以开始逆向推导了。

```
class Solution(object):
    def deckRevealedIncreasing(self, deck):
        """
        :type deck: List[int]
        :rtype: List[int]
        """
        deck.sort()
        i = 0
        res = []
        while deck:
            if i % 2 == 0:
                res.insert(0, deck.pop())
            else:
                res.insert(0, res.pop())
            i += 1
        return res
```
