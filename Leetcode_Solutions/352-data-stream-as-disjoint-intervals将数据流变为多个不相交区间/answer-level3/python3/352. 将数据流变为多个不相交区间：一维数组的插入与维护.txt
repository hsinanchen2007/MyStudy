一次就AC还行，只维护一个$2n$的数组，二分查找坐标插入，如果查找出来的坐标为奇数，则说明插入了已有的区间，为偶数才需要修改区间。

![image.png](https://pic.leetcode-cn.com/65dcd21406447db41ee4cb5f0912bcff5c8e01da3c15103528e228f0ddb9df97-image.png)

```python []
class SummaryRanges:

    def __init__(self):
        self.d = []

    def addNum(self, val: int) -> None:
        m = bisect.bisect(self.d, val)                  #二分查找插入坐标
        if m % 2 == 0:
            if m < len(self.d) and self.d[m] - val == 1:#如果跟右侧区间差值为1时就直接更新右侧区间，为0时不会插入在这里，所以只判断1
                self.d[m] = val
            else:
                self.d.insert(m, val)                   #如果跟区间不相邻就插入区间
                self.d.insert(m, val)
            if m > 0 and self.d[m] - self.d[m - 1] <= 1:#根据现有情况选择是否区间合并
                self.d.pop(m)
                self.d.pop(m - 1)

    def getIntervals(self) -> List[List[int]]:
        return zip(self.d[:: 2], self.d[1:: 2])         #按奇偶顺序打包输出
```
