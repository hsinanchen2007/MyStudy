### 解题思路 
it take maybe too much time to find out our result, just use % and // we can reverse the int. but we should also care about the negative int so we just use cache c to sure positive or negative result to return

### 代码

```python
import numpy as np
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        rev=0
        r_max=np.power(2,31)-1
        r_min=np.power(-2,31)
        #print(r_max,r_min)
        c=x       
        while (x!=0):
            x=abs(x)
            pop=x%10
            #print(pop)
            x=x//10
            #print(x)
            rev=rev*10+pop
            if  rev>r_max or rev<r_min :
                return 0
        if c<0:
            return -rev    
        return rev
```