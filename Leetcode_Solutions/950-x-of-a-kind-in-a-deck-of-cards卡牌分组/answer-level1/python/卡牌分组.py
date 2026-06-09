### 解题思路
此题难点在于，需要用公约数判断是否能进行分组，判断根据是最小公约数是否大于等于2

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        def gcd(i, temp):
            if temp == 0:
                return i
            else:
                return gcd(temp, i % temp)
        set_ = {}
        for i in deck:
            set_[i] = 1 if i not in set_ else set_[i] + 1
        temp = min(set_.values())
        if temp >= 2:
            for i in set_.values():
                if i > temp:
                    if gcd(i, temp) < 2:
                        return False
                    else:
                        temp = gcd(i, temp)
            return True
        else:
            return False
```