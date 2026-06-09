通过一个矩形区域内是否存在船只的API来锁定船只的具体位置，就像是在二维世界做猜数字，一个典型的应对策略就是二分法。而相较于一维数轴上的二分法，二维空间中需要对两个轴同时进行二分，所以每次就有了2*2=4种拆分（当然这里使用三分四分都可以，完全看你喜好）。通过不断地四分当前有船的区域，最终可以将查询范围缩小到一个点，即topRight与bottemLeft相同的查询范围，这样就可以精确地确定出船只的位置。

此外应当注意到的是，在题目给出的API中，查询范围坐标都整数而且**包含**边界，在实现时需要牢记这一点。

在确定了主要思路之后，就可以使用循环或者递归来实现。这里笔者采用代码量更少的递归方法。

首先构建四分区域坐标，在输入topRight和bottemLeft之后，需要对其所围成进行划分，考虑到划分的两个区域边界不应重合，最终的实现代码如下：
```
# 中点分割x，y坐标，且这一边界归在左下的矩形
mx = (topRight.x - bottomLeft.x) // 2 + bottomLeft.x
my = (topRight.y - bottomLeft.y) // 2 + bottomLeft.y
```
在此基础上可以构建出四个子矩形（编号r1-r4）的topRight（后缀b）和bottemLeft点（后缀a），
```
r1a = bottomLeft
r1b = Point(mx, my)

r2a = Point(bottomLeft.x, my + 1)
r2b = Point(mx, topRight.y)

r3a = Point(mx + 1, my + 1)
r3b = topRight

r4a = Point(mx + 1, bottomLeft.y)
r4b = Point(topRight.x, my)
```
在搞清楚了每个矩形的拆分之后，加总所有子矩形中船只的数量，即可得到当前矩形中船只的数量，即可返回：
```
return self.countShips(sea, r1b, r1a) + self.countShips(sea, r2b, r2a) + self.countShips(sea, r3b, r3a) + self.countShips(sea, r4b, r4a)
```
此时递归结构已经完成，需要思考递归的终止条件：
如果topRight和bottemLeft两个点相对继续靠近，稍有常识的人都能看出，当两个点重合时就可以确定一个确切位置上是否有船只。而且对于任意一个区域而言，如果该区域内没有船只则不需要继续拆分查找。所以在函数的开头可以添加如下终止条件：
```
if not sea.hasShips(topRight, bottomLeft):
        return 0
else:
        if topRight.x == bottomLeft.x and topRight.y == bottomLeft.y:
            return 1 # 一个点上只有一条船
```
将以上代码组合，就可以得到一个初步可用的版本：
```
def countShips(self, sea: 'Sea', topRight: 'Point', bottomLeft: 'Point') -> int:
        if not sea.hasShips(topRight, bottomLeft):
            return 0
        else:
            if topRight.x == bottomLeft.x and topRight.y == bottomLeft.y:
                return 1

        mx = (topRight.x - bottomLeft.x) // 2 + bottomLeft.x
        my = (topRight.y - bottomLeft.y) // 2 + bottomLeft.y

        r1a = bottomLeft
        r1b = Point(mx, my)

        r2a = Point(bottomLeft.x, my + 1)
        r2b = Point(mx, topRight.y)

        r3a = Point(mx + 1, my + 1)
        r3b = topRight

        r4a = Point(mx + 1, bottomLeft.y)
        r4b = Point(topRight.x, my)

        return self.countShips(sea, r1b, r1a) + self.countShips(sea, r2b, r2a) + self.countShips(sea, r3b, r3a) + self.countShips(sea, r4b, r4a)
```
在此基础上有什么可以优化的吗？可以发现在查询接近尾声时，可能出现查询区域矩形一个轴向的长度已经为0，此时只需要二分另一个轴的长度即可，节约了调用API的次数。在此基础上稍加调整，即可形成最终的版本(Python3 56ms 13.8MB)
```
def countShips(self, sea: 'Sea', topRight: 'Point', bottomLeft: 'Point') -> int:
        # print(topRight.x, topRight.y, bottomLeft.x, bottomLeft.y)
        if not sea.hasShips(topRight, bottomLeft):
            return 0
        else:
            if topRight.x == bottomLeft.x and topRight.y == bottomLeft.y:
                return 1

        mx = (topRight.x - bottomLeft.x) // 2 + bottomLeft.x
        my = (topRight.y - bottomLeft.y) // 2 + bottomLeft.y
        r1a = bottomLeft
        r1b = Point(mx, my)
        count = self.countShips(sea, r1b, r1a)
        if topRight.x != bottomLeft.x:
            r4a = Point(mx + 1, bottomLeft.y)
            r4b = Point(topRight.x, my)
            count += self.countShips(sea, r4b, r4a)
        if topRight.y != bottomLeft.y:
            r2a = Point(bottomLeft.x, my + 1)
            r2b = Point(mx, topRight.y)
            count += self.countShips(sea, r2b, r2a) 
        if topRight.x != bottomLeft.x and topRight.y != bottomLeft.y:
            r3a = Point(mx + 1, my + 1)
            r3b = topRight
            count += self.countShips(sea, r3b, r3a)
        return count
```
至此问题得到解决。而在复盘时笔者注意到：题目限制了矩形内至多只有 10 艘船。那么能否利用这一条件限制提升程序的效率呢？比如当出现了10个互不重叠的有船矩形时，可以认为船只数量就是10而无需确定船只的精确位置。然而笔者年少，思想单纯，方法朴素便不再班门弄斧，还是要学习一个，还请各位不吝赐教。





