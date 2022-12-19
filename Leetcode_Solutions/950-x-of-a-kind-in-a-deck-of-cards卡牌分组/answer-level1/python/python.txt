### 解题思路
先求出每个牌的个数，然后求出所有牌的个数的最大公约数，大于等于2则true

### 代码

```python
class Solution(object):
    def hasGroupsSizeX(self, deck):
        """
        :type deck: List[int]
        :rtype: bool
        """
        def gcd(num):
            num.sort()
            gcdl = []
            for i in range(1, num[0] + 1):
                for index, j in enumerate(num):
                    if j % i == 0:
                        if (index + 1) == len(num):
                            gcdl.append(i)
                            break
                        continue
                    else:
                        break
            if not gcdl:
                return 1
            else:
                return sorted(gcdl)[-1]
        if len(deck)<=1:
            return False
        if len(deck)==2 :
            if deck[0] == deck[1]:
                return True
            else:
                return False
        deck.sort()
        li = []
        k = 1
        for i in range (0, len(deck)):
            if i == 0:
                k = 1
                continue
            if deck[i] ==  deck[i-1]:
                k += 1
                continue
            if deck[i] != deck [i-1]:
                li.append(k)
                k = 1
                continue
        li.append(k)
        x = gcd(li)
        if(x>=2):
            return True
        return False

        
```