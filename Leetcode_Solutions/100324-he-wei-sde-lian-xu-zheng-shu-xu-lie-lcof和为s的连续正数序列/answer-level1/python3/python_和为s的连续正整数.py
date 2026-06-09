### 解题思路
纯数学法：
连续整数个数为range(2,int((math.sqrt(1+8*target))/2-0.5)+1)
如果存在连续整数，那么一定能被0.5整除
基于以上两点，在平均值左右寻找相应长度的连续整数
空间复杂度O(mn) 超过100%
时间复杂度大于O(m),和O(n)比未知，优化math和反转数列时间可以更快

### 代码

```python3
import math
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        conSeq=[]
        if target==1:
            return conSeq
        for n in range(2,int((math.sqrt(1+8*target))/2-0.5)+1):
            ave=float(target/n)
            if ave%1.0 == 0.0:
                if n%2==1:
                    curSeq=[i for i in range(int(ave-(n-1)/2),int(ave+(n-1)/2)+1)]
                    conSeq.append(curSeq)
            elif ave%0.5 == 0.0:
                curSeq=[i for i in range(int(ave-n/2+1),int(ave+n/2+1))]
                conSeq.append(curSeq)
            else:
                continue
        return conSeq[::-1]
```