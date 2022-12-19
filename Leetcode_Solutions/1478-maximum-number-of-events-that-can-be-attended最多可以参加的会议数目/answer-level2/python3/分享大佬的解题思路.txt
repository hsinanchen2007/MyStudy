### 解题思路
拜读大佬的思路 coordinate_blog  https://blog.csdn.net/qq_17550379/article/details/104349449 感谢感谢

解题的思路是最重要的：
开始有点想偏了，就想着两种策略，第一种如果某一个会议只有一天，就让他先占，然后逐步筛选。
第二种策略是，如果某个一天，只有一个会议，那么就先占用上，然后逐步筛选。
但是后来发现这两种策略，最后都有问题。
膜拜大佬的解题思路：
我们将events按照startDayi从小到大排序，然后遍历每一天i，将第i天可以参加的会议都添加到队列q中。例如，示例5中第一天满足条件的会议如下：

[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]
选取结束日子最早的那个会议，占用。

接着将q中的会议按照endDayi从小到大排序（采取贪心策略，选取第i天满足条件的会议中endDayi最小的那个）。然后从q中取出第一个满足条件（startDayi <= d <= endDayi）的event（弹出例子中的[1,1]），然后记录第i天可以参加（也就是参会数+1）。如果q为空并且所有的event都使用过的，此时然会结果即可。


### 代码

```python3
class Solution:
    def maxEvents(self, events) -> int:
        events.sort()
        res, index, n = 0, 0, len(events)
        q = []

        l, r = 100000, 0
        for i, j in events:
            l, r = min(l, i), max(r, j)

        for i in range(l, r + 1):
            while index < n and events[index][0] <= i <= events[index][1]:
                q.append(events[index])
                index += 1
            # print('q',q)
            # exit()

            if not q and index == n:
                return res

            q.sort(key=lambda v: (v[1], v[0]))
            while q:
                pre = q.pop(0)
                if pre[0] <= i <= pre[1]:
                    res += 1
                    break
        return res
```