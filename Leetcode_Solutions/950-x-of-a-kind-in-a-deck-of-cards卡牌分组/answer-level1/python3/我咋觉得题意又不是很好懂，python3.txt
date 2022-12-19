```
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        from collections import Counter
        counter=Counter(deck)

        count=list(counter.values())
        max_val=max(count)  #公约数肯定不超过出现次数的最大值
        
        for i in range(2,max_val+1):    #公约数不一定是卡牌上出现的，大于2就可以了
            if all(not count[j]%i for j in range(len(count))):  #判断是否是公约数
                return True
        return False
```
