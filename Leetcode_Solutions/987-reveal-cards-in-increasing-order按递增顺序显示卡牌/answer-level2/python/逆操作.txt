## 思路

**将所有操作反向进行有可以了**

```
1. 从牌组顶部抽一张牌，显示它，然后将其从牌组中移出。 (逆操作： 将牌放到牌组顶部)
2. 如果牌组中仍有牌，则将下一张处于牌组顶部的牌放在牌组的底部。（逆操作： 如果牌组中有牌，将牌组底部的牌放在牌组的顶部）
3. 如果仍有未显示的牌，那么返回步骤 1。否则，停止行动。(逆操作： 先步骤2， 再步骤1)
```

所以最终操作步骤

```
0. 将牌组倒序排序，放到手上
1. 如果结果牌组中有牌，将牌组底部的牌放在牌组的顶部
2. 将牌放到牌组顶部
3. 如果手上还有牌，那么返回步骤 1。否则，停止行动。
```

## 代码

```python
class Solution(object):
    def deckRevealedIncreasing(self, deck):
        """
        :type deck: List[int]
        :rtype: List[int]
        """
        from collections import deque
        deck.sort(reverse=True)
        ans = deque()
        for i in deck:
            if ans:
                ans.appendleft(ans.pop())
            ans.appendleft(i)
        return list(ans)
```