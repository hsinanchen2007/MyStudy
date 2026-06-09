### 解题思路
参考了力友“[liweiwei1419](https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards/solution/qiu-jie-zui-da-gong-yue-shu-java-by-liweiwei1419/)”的思路，
我也是困在了最大公约数的计算和使用上，学习了，感谢！

### 代码

```python3
class Solution:

    def gcd(self, a, b):
        if b == 0:
            return a
        return self.gcd(b, a%b)

    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        lgth = len(deck)
        if lgth < 2:
            return False

        dct = {}
        for item in deck:
            if item not in dct.keys():
                dct[item] = 1
            else:
                dct[item] += 1
        
        cnt_min = min(dct.values())
        if cnt_min < 2:
            return False
        
        x = dct[deck[0]]
        for val in dct.values():
            if val == 1:
                return False
            
            x = self.gcd(x, val)
            if x == 1:
                return False

        return True
```