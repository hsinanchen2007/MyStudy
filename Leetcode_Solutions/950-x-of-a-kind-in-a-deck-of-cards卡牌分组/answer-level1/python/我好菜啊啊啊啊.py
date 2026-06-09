### 解题思路
我好菜啊啊啊爱哎啊啊啊

### 代码

```python3
import math
class Solution:
    def hasGroupsSizeX(self, deck) -> bool:
        deck = sorted(deck)
        gcdd = -1
        num_of_it = 1
        for i in range(1, len(deck), 1):
            if deck[i] == deck[i - 1]:
                num_of_it += 1
            else:
                if num_of_it == 1:
                    return False
                if gcdd == -1:
                    gcdd = num_of_it
                else:
                    gcdd = math.gcd(gcdd, num_of_it)
                    if gcdd == 1:
                        return False
                num_of_it = 1
        
        if gcdd == -1:
            gcdd = num_of_it
            
        return True if math.gcd(gcdd, num_of_it) != 1 else False


```