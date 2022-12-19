### 解题思路
![WCVREYQGO~9FH\[05S)RBP}M.png](https://pic.leetcode-cn.com/e62ce25a6c108981e05b26f0762fb5a45610c7983c8f70e5fbef18c488c4625e-WCVREYQGO~9FH%5B05S\)RBP%7DM.png)



### 代码

```python
class Solution(object):
    def distributeCandies(self, candies, num_people):
        """
        :type candies: int
        :type num_people: int
        :rtype: List[int]
        """
        x=0
        now=1
        used=0
        ans=[0]*num_people
        while(now<candies-used):
            if x<num_people:
                ans[x]=ans[x]+now
                used=used+now
                now+=1
                x+=1
            else:
                x=0
                ans[x]=ans[x]+now
                used=used+now
                now+=1
                x+=1
        if(x<num_people):
            ans[x]=ans[x]+candies-used
        else:
            ans[0]=ans[0]+candies-used
        return ans


```