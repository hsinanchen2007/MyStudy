### 解题思路
先求出每种数有多少个，放进字典，然后求这些数的最大公因数是不是大于2就可以了。
利用reduce函数和辗转相除法求出所有数的最大公约数

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        d = {}
        for num in deck:
            try:
                d[num] += 1
            except:
                d[num] = 1
        #接下来只需要字典中所有值的大于2的公约数
        return reduce(self.MaxGcd, collections.Counter(d).values()) > 1
    
    def MaxGcd(self,big,small):
        if big%small == 0:
            return small
        remain = big % small
        if remain > small:
            return self.MaxGcd(remain,small)
        else:
            return self.MaxGcd(small,remain)
```