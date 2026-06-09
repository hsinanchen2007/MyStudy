1. 先用Counter统计每张牌的数量
2. 再对Counter的键排序得到牌的有序集合
3. 按照从小到大来取牌，每取n张X牌把n串顺子[X,X+1,...X+W-1]取走
4. 如果其中牌个数不够取返回False，够取返回True
```
from collections import Counter
class Solution:
    def isNStraightHand(self, hand: List[int], W: int) -> bool:
        n = len(hand)
        if n % W != 0:
            return False
        counter = Counter(hand)
        cards = sorted(counter)
        for card in cards:
            if counter[card] < 0:
                return False
            if counter[card] > 0:
                for i in range(1,W):
                    if card + i not in counter:
                        return False
                    else:
                        counter[card+i] -= counter[card]
        return True
```
