### 解题思路
此处撰写解题思路
学习了一个函数  counter的用法
### 代码

```python3
from collections import Counter
class Solution:
    def isNStraightHand(self, hand: List[int], W: int) -> bool:
        if len(hand)%W !=0:
            return False
        hand.sort()
        count=Counter(hand)
        print(count[2])
        for i,data in enumerate(hand):
            if count[data]>0:
                num_data=count[data]
                for i in range(W):
                    count[data+i]=count[data+i]-num_data
                    if  count[data+i]<0:
                        return False
        return True

                
            


```