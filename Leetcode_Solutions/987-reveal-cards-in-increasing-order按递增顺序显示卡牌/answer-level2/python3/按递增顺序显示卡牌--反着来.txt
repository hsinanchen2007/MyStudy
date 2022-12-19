#### 取牌步骤：从牌堆D中取出顶部的牌放到序列S末尾，再把新的顶牌放到下面。重复直到D空，最后构成一个递增序列S。

#### 现在反着来：把牌堆D的底部牌放到顶部，再把S末尾的牌放到D顶部。重复直到S空。

---

```
from collections import deque

class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        dq = deque()
        deck.sort()
        for v in deck[::-1]:
            if dq:
                dq.appendleft(dq.pop())
            dq.appendleft(v)

        return list(dq)
```
