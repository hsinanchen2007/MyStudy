![image.png](https://pic.leetcode-cn.com/ef5972c8c51712f503416e18b787995185ae399e855cf2541b324e2bcaed9254-image.png)


模拟加桶必超时，有点像公交人数报数，第i个航空公司就是第i个站点，num就是第i个航空公司的预定人数，相当于公交车在每个站点实时的人数，该题里面存成了列表输出，相当于记录各个公交站点的实时人数，up和down分别记录到第i站时上下车的人数。


```
class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        up=[0]*(n+1)
        down=[0]*(n+1)
        for book in bookings:
            up[book[0]]+=book[2]
            down[book[1]]+=book[2]
        num=up[1]
        ans=[num]
        for i in range(2,n+1):
            num+=up[i]-down[i-1]
            ans+=[num]
        return ans
```
