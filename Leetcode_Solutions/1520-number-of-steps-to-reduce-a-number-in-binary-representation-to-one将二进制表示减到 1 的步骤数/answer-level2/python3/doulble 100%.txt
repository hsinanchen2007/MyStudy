### 解题思路
此处撰写解题思路
I do not understand why I have to use // but not /??

### 代码

```python3
import numpy as np
class Solution:
    def numSteps(self, s: str) -> int:
        l=len(s)
        #print(l)
        sum=0
        for i in s:
           #print(i)
           i=int(i)
           if i!=0:
             sum=sum+2**(l-1)
             #print(sum)
           else:
             sum=sum
        #print(sum)
           l=l-1
          #print(sum)
        count=0
        while(sum>1):
            cache=sum%2
            if cache==0:
                sum=sum//2
                count=count+1
            else:
                sum=sum+1
                count=count+1
        return count
```