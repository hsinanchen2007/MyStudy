### 解题思路
整体用的二分法,从0查到其平方根取整位置
要注意两个特殊情况：
1.a=0，b=sqrt(c)
2.a==b

### 代码

```python
import math
class Solution(object):
    def judgeSquareSum(self, c):
        i = 0
        j = int(math.sqrt(c))
        while(i <= j):
            sqsum = i * i + j * j
            if(sqsum == c):
                return True
            elif(sqsum < c):
                i += 1
            else:
                j -= 1
        return False
```