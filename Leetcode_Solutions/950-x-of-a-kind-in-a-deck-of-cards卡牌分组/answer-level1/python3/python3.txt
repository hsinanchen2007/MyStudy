### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        C = []
        a = 0
        for i in set(deck):
            c = deck.count(i)
            C.append(c)
        b = min(C)
        if b < 2:
            return False
        else:
            for i in range(2, b+1):
                if all(j%i == 0 for j in C):
                    return True
            return False



       
            


```