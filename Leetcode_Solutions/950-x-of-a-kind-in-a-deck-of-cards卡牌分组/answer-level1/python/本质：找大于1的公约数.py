### 解题思路
假设有K种不同数字的卡片，每种卡片有Ck张
那么我们要找出C1,C2,...,CK是否存在共同的大于1的公约数

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        N=len(deck)
        counts = dict()
        if N==1:
            return False
        for i in deck:
            counts[i] = counts.get(i, 0) + 1
        
        min_card=min(counts.values())
        if min(counts.values())==1:
            return False
        #if count_val has a common divisor X and X>=2 ->True else False e.g. 11 333 444444 (2,3,6 no common divisor->False)
        count_val=list(counts.values())
        count_val.sort()

        for i in range(len(count_val)-1):
            if gcd(count_val[i],count_val[i+1])==1:
                return False
        return True


    def gcd(c,b):
        while b:
            c,b=b,c%b
        return(c)  


```