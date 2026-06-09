### 解题思路
通过字典选出出现次数最少的数，然后求出这个数的各个因子，历遍所有因子

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
            import math
            if len(deck) <= 1:
                return False
            Hash = dict()
            for i in range(len(deck)):
                if not Hash.get(deck[i]):
                    Hash[deck[i]] = 1
                else:
                    Hash[deck[i]] += 1
            key = min(Hash.values())
            if key < 2:
                return False
            sta_list = [i for i in range(2, math.ceil(key**0.5) + 1) if key % i==0]
            sta_list2 = [key//i for i in sta_list if i!= key]
            sta_list = sta_list + sta_list2 + [key]
            for s in sta_list:
                num = 0
                if key % s == 0:
                    for i in Hash:
                        if Hash[i] % s != 0:
                            break
                        else:
                            num += 1
                if num == len(Hash):
                    return True
            return False
```