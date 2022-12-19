## 思路
+ 很多题解写得很清楚啦，就是切比雪夫距离问题。
+ 这里简单描述一下。
+ 即，假设两个点之间的横坐标之差为`x`，纵坐标之间距离是是`y`，它们之间的差是`abs(x-y)`
+ 我们的点从第一个点到第二个点的最小步数是多少呢？
+ 因为我们走斜线相当于一步代替两步，所以要尽可能以斜线为主。
+ 走斜线就是一个走正方形的过程。
+ 我们就让它尽可能走正方形。
+ 但是由于`x`和`y`不一定相等
+ 所以我们可以，先走正方形，然后走多出来的那条边的步数。
+ 即，两点之间的最短步数就是`max(x,y)`
+ 很多题解写得代码也很简单易于理解，我这里放上一行的代码，算是带大家温习一下列表生成式的概念。

## 代码
```python
class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        return sum(max(abs(points[i+1][0]-points[i][0]),abs(points[i+1][1] - points[i][1])) for i in range(len(points)-1))
```