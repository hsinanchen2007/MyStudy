### 解题思路
记录每个值的数量，选取最小的一个，获取最小的那个的所有因数
如果要符合要求，那么X必然是所有因数中的一个，并且X>=2
暴力求解即可。

### 代码

```python3
import math
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        countor = {}
        for i in range(0, len(deck)):
            if deck[i] not in countor.keys():
                countor[deck[i]] = 0
            countor[deck[i]] += 1
        mmin = min(countor.values())
        
        # print(mmin)
        if mmin <= 1:
            return False
        
        # 获取所有因数
        yin = []
        for i in range(2, mmin+1):
            if mmin % i == 0:
                yin.append(i)
        
        for mm in yin:
            # print(mm)
            flag = True
            for k, v in countor.items():
                if v % mm != 0:
                    flag = False
            if flag:
                return flag
        # print(countor)
        return False
```