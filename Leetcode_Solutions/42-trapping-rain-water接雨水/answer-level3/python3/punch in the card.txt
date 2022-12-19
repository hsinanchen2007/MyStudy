### 解题思路

kick the card. 
Again, I will give you code. 

### 代码

```python3
from typing import *

class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height)<3:
            return 0
        out=0;
        l=[0 for i in range(len(height))]
        r=[0 for i in range(len(height))]
        for i in range(1,len(height)):
            l[i]=max(height[i-1],l[i-1])
        for i in range(len(height)-2,-1,-1):
            r[i]=max(height[i+1],r[i+1])
        for i in range(1,len(height)-1):
            tmp=min(r[i],l[i])
            if height[i] < tmp:
                out+=tmp-height[i]
        return out

```