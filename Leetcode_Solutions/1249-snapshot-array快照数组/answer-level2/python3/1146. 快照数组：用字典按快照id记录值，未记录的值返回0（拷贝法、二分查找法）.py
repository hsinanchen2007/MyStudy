![image.png](https://pic.leetcode-cn.com/1d68b2481cbeb813717e1ed419852573ba397f67292a4b2d5c0dd753be419806-image.png)

用一个版本字典d记录版本编号及其index和val的记录情况，更新版本的时候就复制上一个版本的字典，继续记录。

浅拷贝的效率也很高，所以时间并不算慢，最快有552ms，比赛的时候写了能过，不过这种方法的空间相对比较大。

![image.png](https://pic.leetcode-cn.com/fc14b95dacc445ee7f7bb0c832e3b3042f862d610091f5d2c87abc3b603b9ff8-image.png)

```py
class SnapshotArray:

    def __init__(self, length: int):
        self.d = {0:{}}     #初始版本
        self.t = 0          #初始快照id

    def set(self, index: int, val: int) -> None:
        self.d[self.t][index] = val

    def snap(self) -> int:
        self.t += 1
        self.d[self.t] = self.d[self.t - 1].copy()              #复制（浅拷贝）前一个版本
        #self.d[self.t] = dict(self.d[self.t - 1])  
        #self.d[self.t] = {**self.d[self.t - 1]}                                #前三种写法，效率差不多
        #self.d[self.t] = {i: v for i, v in self.d[self.t - 1].items()}
        #self.d[self.t] = {i: self.d[self.t - 1][i] for i in self.d[self.t - 1]}#后两种写法效率相对比较低
        return self.t - 1

    def get(self, index: int, snap_id: int) -> int:
        return self.d[snap_id][index] if index in self.d[snap_id] else 0    #在该版本里存在index就输出对应得val，否则输出0
```



空间上更优越的做法就是记录每个index在每个版本下面的不同值，然后通过二分查找来确定具体值，如果查找的版本在第一个版本之前或者不存在这个index，就返回0。

对于这题来说实际上空间也没少太多，而且二分查找的边界还得反复确认，如果是比赛的时候，还是建议写前一个版本。

![image.png](https://pic.leetcode-cn.com/368172f1dcfe8c976df7522cb5b2f5e57f32667700df1aeb76bb433ae2aa445e-image.png)


```py
class SnapshotArray:

    def __init__(self, length: int):
        self.d = collections.defaultdict(list)
        self.t = 0

    def set(self, index: int, val: int) -> None:
        if index not in self.d or self.t != self.d[index][-1][0]:   #如果index不存在，或者快照id大于最后一次修改的id    
            self.d[index] += [[self.t, val]]                        #就新增版本
        else:
            self.d[index][-1][1] = val                              #反之，同一层快照下面只用改值，不增加新版本

    def snap(self) -> int:
        self.t += 1
        return self.t - 1

    def get(self, index: int, snap_id: int) -> int:
        if index in self.d and snap_id >= self.d[index][0][0]:      #如果index存在，且查看id大于等于首次修改的id就继续
            snap_index = bisect.bisect(self.d[index], [snap_id, float('inf')])  #二分查找右插入
            return self.d[index][snap_index - 1][1]                             #返回插入编号左边的版本的值
        return 0
```
