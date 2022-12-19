### 解题思路
X就是牌中每个数字出现次数的最大公约数，利用reduce函数即可求得。

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        d={}
        for i in deck:
            if i not in d:
                d[i]=0
            d[i]+=1
        return reduce(math.gcd,d.values())>=2
```