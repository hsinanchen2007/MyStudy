原理就是按顺序记录预定情况，start：+1，end：-1，每增加一个预定后统计累加订单计算过程中的峰值，具体思路在评论区有写，大佬 如寒灬 已经解释得比较清楚了。

问题就在操作上，如何有序插入，于是就写了一个二分插排，这样每次插入就是O(logn)，输出统计是O(n)，n为累计订单长度。

看到评论区里有先插入进总订单，然后再系统快排的做法，这样每次插入都会是O(nlogn)以上，而且相对有序的数组算是快排的糟糕情况之一，时间应该不会更好，还不如普通插排呢，好在数据量不大，貌似也能AC。

其实统计输出理论上还有可能用线段树优化成O(logn)的输出，应该可以再降半个数量级的时间，但太麻烦了就不写了。

![image.png](https://pic.leetcode-cn.com/651fb8073eb85693f03e1c19984e72946243cd4727f07d2251583bc231783aa0-image.png)

(PS: 用python3 AC 的人好少啊，提交报告里时间排名肉眼可数)


调用系统二分查找的方法：

```py
class MyCalendarThree:

    def __init__(self):
        self.tl = [[-float('inf'), 0]]       #插排数组初始化

    def book(self, start: int, end: int) -> int:
        tl = self.tl
        def tlAdd(ind, t):
            m = bisect.bisect(tl, [ind, t]) #返回插在右边时的坐标
            if ind == tl[m-1][0]:
                tl[m-1][1] += t             #如果与左边的相等就合并进去
            else:
                tl.insert(m, [ind, t])      #与左边不等就正常插入
        tlAdd(start, 1)
        tlAdd(end, -1)
        ans = 0
        s = 0
        for _, t in tl:                     #相当于输出tl[i][1]
            s += t
            ans = max(ans, s)               #统计累加订单计算过程中的峰值
        return ans
```

手写二分插入排序的方法：

```py
class MyCalendarThree:

    def __init__(self):
        self.tl = [[-float('inf'), 0], [float('inf'), 0]]

    def book(self, start: int, end: int) -> int:
        tl = self.tl
        def tlAdd(ind, t):          #插入排序
            l, r = 1, len(tl) - 1
            while l <= r:
                m = (l + r) // 2
                if ind < tl[m-1][0]:
                    r = m - 1
                elif ind > tl[m][0]:
                    l = m + 1
                else:
                    if ind == tl[m][0]:     #如果在插入点周围存在相等的相同的预定时间就合并订单
                        tl[m][1] += t
                    elif ind == tl[m-1][0]:
                        tl[m-1][1] += t
                    else:
                        tl.insert(m, [ind, t])      #没出现相同的预定时间就正常插入
                    return
        tlAdd(start, 1)
        tlAdd(end, -1)
        ans = 0
        s = 0
        for _, t in tl:             #相当于输出tl[i][1]
            s += t
            ans = max(ans, s)       #统计累加订单计算过程中的峰值
        return ans
```
