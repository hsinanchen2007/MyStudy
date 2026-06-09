### 解题思路
维护一个单调非递减队列，队列中的第一个元素即为最低价

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        q=[]
        res=0
        for i in prices:
            while q and q[-1]>i:
                t=q.pop()
                if q:
                    res=max(res,t-q[0])
            q.append(i)
        if len(q)>=2:
            res=max(res,q[-1]-q[0])
        return res
```