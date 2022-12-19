1. 首先判断列表元素个数，不是W的整数倍肯定False
2. 元素从小到大排序.sort()方法仅列表类型具备，sorted()方法适用于多种数据类型
3. 列表的.remove()方法仅删除遇到的第一个匹配元素，因此从列表的第一个元素开始，相继删除list[0]至list[0]+W的所有元素，删完第一轮代表找出了第一套顺子，接下来不断循环，如果发现list[0]至list[0]+W的某元素不在列表中，表明缺牌，返回FALSE 即可，如果最终列表被删空，说明满足要求，返回True。
  
```python []
  def isNStraightHand(self, hand, W):
        if len(hand)%W != 0:
            return False
        hand.sort()
        while (len(hand) > 0):
            first_num = hand[0]
            for j in range(W):
                if first_num + j in hand:
                    hand.remove(first_num + j)
                    if hand == []:
                        return True
                else:
                    return False
```
