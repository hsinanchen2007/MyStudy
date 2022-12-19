思路基本就是试错法。
首先符合条件的整数一定不是完全平方数，因为完全平方数因数一定是奇数个，先排除。
对于每个x让i从2到比sqrt(x)小的第一个整数循环。每找到一个加入列表，若仅能找到一个因数，即符合要求，这时这个因数对应一个＞sqrt(x)的另一因数，加上1和x正好四个数。，每当列表中存放的数目超过1，说明>=6个因数不符合要求，直接break进入下一个x外循环，当列表中只有一个数的时候（列表为空，即x只有两个因数的情况不符合）说明x符合条件，对res加上x的四个因数值。
```
class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        res = 0
        for x in nums:
            sqrt = x**0.5
            second = []
            if int(sqrt)==sqrt:
                continue
            else:
                a = int(sqrt)+1
            for i in range(2,a):
                if x%i == 0:
                    second.append(i)
                    if len(second)>1:
                        break
            if len(second)==1:
                res += 1+x+int(second[0])+int(x/second[0])
                    
        return res
```
