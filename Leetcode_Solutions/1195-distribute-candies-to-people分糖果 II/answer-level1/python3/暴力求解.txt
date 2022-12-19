### 解题思路
暴力求解，代码不够简洁。改进：
while循环终止条件改为糖果发完：while candies>0
判断发多少糖果：ans[i]+=min(num,candies)
candies=max(candies-num,0)

### 代码

```python3
import numpy as np
class Solution:
    def distributeCandies(self, candies, num_people):
        ans=np.zeros(num_people)
        i=0
        num=1
        while True:
            if candies//num==0:
                ans[i]+=candies
                return [int(i) for i in ans]
            else:
                if candies>=num:
                    candies-=num
                else:
                    num=candies
                    candies=0
                # print(i)
                ans[i]+=num
                num+=1
                i=(i+1)%num_people
```