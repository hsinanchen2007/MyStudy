## 思路


1. 创建一个字典 `hand_counter`，用于统计每张牌出现的数量。例如 `hand_counter[i] = x` 表示牌 `i` 出现 `x` 次
2. 根据字典的 Key 值进行升序排序，获得排序后的列表 `sort_hand`
3. 取连续牌。若要取的牌 `i` 有 `n` 张，那么需要将 `i, i + 1, ..., i + W - 1` 牌都取走 `n` 张。若在取牌过程中某张牌的数量不够则返回 `False`，整个取牌过程顺利则返回 `True`

## 手写实现

```python
class Solution:
    def isNStraightHand(self, hand: List[int], W: int) -> bool:
        length = len(hand)
        # 无法整除直接返回 false
        if length % W != 0:
            return False
        
        # 初始化辅助空间
        hand_counter = dict()
        
        for i in range(length):
            hand_counter[hand[i]] = hand_counter.get(hand[i], 0) + 1
        # 排序
        sort_hand = sorted(hand_counter)
                    
        for h in sort_hand:
            if hand_counter[h] == 0:
                continue
            elif hand_counter[h] < 0:
                return False
            else:
                for i in range(1, W):
                    if hand_counter.get(h + i, 0) == 0:
                        return False
                    else:
                        hand_counter[h + i] -= hand_counter[h]
            
        return True
```

## 借助 Counter 实现

```python
from collections import Counter

class Solution:
    def isNStraightHand(self, hand: List[int], W: int) -> bool:
        hand_counter = Counter(hand)
        # 按 key 值排序结果
        sort_hand = sorted(hand_counter)
         
        for h in sort_hand:
            # 牌不够取了
            if hand_counter[h] < 0:
                return False
            elif hand_counter[h] > 0:
                for i in range(1, W):
                    if hand_counter[h + i] == 0:
                        return False
                    else:
                        hand_counter[h + i] -= hand_counter[h]
            else:
                # == 0 时跳过
                continue
            
        return True
```