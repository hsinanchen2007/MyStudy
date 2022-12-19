### 解题思路
首先想到的肯定是对每个bookings当中的booking进行遍历，当然结果也是超出限制而失败，参考了几位大佬们的思路结合一下自己的理解：航班只有n趟，相比于brute force遍历的方法，我们只需要**记录下每趟航班（每个索引点处）的净增长人数**即可，booking的形式是给出航班索引的起点、终点和人数，那么**起点索引相当于净增长人数为正，终点索引相当于净增长为负**，我们只需要记录下每个航班的净增长人数就能得到最终的结果。实际操作当中我们对bookings进行遍历，把每个索引或者说每趟航班的净增加人数记录在一个长度为n的数组res里，之后再对整个res数组从头也就是第一趟航班开始累加，类似于numpy里面的cumsum一样，最终得到的就是所有航班的人数。
作为一个渣渣，应该拥有的自我修养，就是首先要熟悉暴力解法怎么做，然后再考虑暴力解法基础上深入理解题目的思路弄清问题的本质，然后进行优化甚至找到最优解，一步一步慢慢来嘛＜(▰˘◡˘▰)

### 代码

```python3
class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        res = [0]*n
        for booking in bookings:
            res[booking[0]-1] += booking[2]
            if booking[1] < n:
                res[booking[1]] -= booking[2]
        for i in range(1, n):
            res[i] += res[i-1]
        return res
```