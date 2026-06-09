### 解题思路
执行用时 :996 ms, 在所有 Python3 提交中击败了94.86%的用户
内存消耗 :27.7 MB, 在所有 Python3 提交中击败了7.14%的用户

### 代码

```python3
class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        ans=[0]*(n+1)
        for start,end,seats in bookings:
            ans[start-1]+=seats
            ans[end]-=seats
        for i in range(n):
            ans[i+1]+=ans[i]
        return ans[:-1]
```