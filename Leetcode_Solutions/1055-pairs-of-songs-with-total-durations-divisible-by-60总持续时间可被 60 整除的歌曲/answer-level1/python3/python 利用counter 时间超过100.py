先将所有的数取60的余数
接着用Counter统计每个出现的余数
遍历所有小于30的数x
找60-x出现的次数取一个乘积就是有多少种组合

注意两个special case
一个是0 一个是30 这两个取组合数即可
```
from collections import Counter
from scipy.special import comb
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        length = len(time)
        sum = 0
        for i in range(0,length):
            time[i] %= 60
        c1 = Counter(time)
        print(c1)
        for i,v in c1.items():
            if not i == 0 and i <30:
                sum += v*c1[60-i]
            if i == 30:
                sum += comb(c1[30],2)
        print(sum)
        #special case
        sum = int(sum + comb(c1[0],2))
        return sum
```
