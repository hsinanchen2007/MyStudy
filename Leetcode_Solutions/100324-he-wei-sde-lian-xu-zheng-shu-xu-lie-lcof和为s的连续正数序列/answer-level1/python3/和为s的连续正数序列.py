### 解题思路
利用对称的思想。
（1）连续正数有奇数个时，必定以某个整数为对称数，此时我们知道正数的个数和对称中心就能得到序列。
（2）连续正数有偶数个（假设是i个）时，那么必定以（b[1]=target/i)为对称中心，range(int(b[1]-i//2)+1,int(b[1]+i//2)+1)])就是序列的范围

### 代码

```python3
import math
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        result=[]
        num = [i for i in range(2,int(target/2))]
        num.reverse()
        for i in num:
            b = math.modf(target/i)
            if (i%2 !=0 and b[0]==0 and b[1]>(i//2)):
                result.append([j for j in range(int(b[1]-(i//2)),int(b[1]+(i//2)+1))])
            if (i%2 == 0 and b[0]==0.5 and b[1]>=(i//2)):
                result.append([j for j in range(int(b[1]-i//2)+1,int(b[1]+i//2)+1)])
        return(sorted(result))
```