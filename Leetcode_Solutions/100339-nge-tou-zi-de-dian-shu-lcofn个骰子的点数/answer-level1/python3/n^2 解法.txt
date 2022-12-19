Solution:

计算一个二维dp列表，这个二维dp列表的第一维度代表用了几个骰子，第二维度代表了数值达到几。

```
from collections import Counter
import math
class Solution:
    def twoSum(self, n: int) -> List[float]:
        if n==0: return [0]
        
        dpdict = {}
        for i in range(n):
            for j in range(i+1,6*(i+1)+1):
                if i==0:
                    dpdict[i,j] = 1/6
                else:
                    sum_prob = 0
                    num = 1
                    while num <=6:
                        if j-num <6*(i)+1 and j-num>=i:
                            sum_prob += dpdict[i-1,j-num] *1/6
                        num+=1
                    dpdict[i,j] = sum_prob

        re = [dpdict[i,j] for j in range(i+1,6*(i+1)+1)]
        return re

```
