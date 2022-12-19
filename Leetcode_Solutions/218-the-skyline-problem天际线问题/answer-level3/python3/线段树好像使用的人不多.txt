### 解题思路
线段树本身是一种高级数据结构，但构建出一棵线段树后题解思路是相对容易懂的。

首先，收集建筑物的x坐标用于构建线段树。

测试用例中有[[0,2147483647,2147483647]]这样的例子即可得知，如果我们构建一棵范围在[0,2147483647]的线段树是很不效率的。
所以我们建立一个x坐标的映射，将它们缩小至[0:len(x坐标总数)]的范围。

这是一个维护区间最大值的线段树，为更新方便，将建筑物的高度从小到大排序，直接覆盖该区间的值，就不会破坏线段树的区间最大值。

最后对于线段树的每一个点查询它的最大值即可生成天际线。

### 代码

``` python3
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        if len(buildings) == 0:
            return []
        # 收集建筑物的x坐标
        geometricX = self.getGeometricX(buildings)
        # 把建筑物的x坐标映射到一个[0:len(geometricX)]的范围
        geometricXMap = {geometricX[i] : i for i in range(len(geometricX))}
        segmentTree = MultiOverwriteSegmentTree([0 for i in range(len(geometricX))])
        # 将建筑物的高度从小到大排序
        buildings.sort(key = lambda x : x[2])
        # 更新线段树区间
        for start, end, height in buildings:
            segmentTree.updateRange(geometricXMap[start], geometricXMap[end]-1, height)
        result = []
        # 生成天际线
        for i in range(len(geometricX)):
            realX = geometricX[i]
            currentHeight = segmentTree.getRange(i, i)
            if not result or currentHeight != result[-1][1]:
                result.append([realX, currentHeight])
        return result

    # 收集建筑物的x坐标并排序
    def getGeometricX(self, buildings):
        geometricX = set()
        for start, end, height in buildings:
            geometricX.add(start)
            geometricX.add(end)
        return sorted(geometricX)
```
### 附：线段树

``` python3
class Node:
    def __init__(self, startIndex, endIndex, val):
        self.start = startIndex
        self.end = endIndex
        self.val = val
        # lazy更新法
        self.lazyVal = None
        self.left = None
        self.right = None

class MultiOverwriteSegmentTree:
    def __init__(self, data):
        self.data = data
        self.root = self._buildTree(0, len(self.data)-1)

    def _buildTree(self, start, end):
        if start == end:
            return Node(start, end, self.data[start])
        
        root = Node(start, end, 0)
        mid = (start + end) // 2
        root.left = self._buildTree(start, mid)
        root.right = self._buildTree(mid+1, end)
        root.val = max(root.left.val, root.right.val)
        return root

    def updateRange(self, i, j, val):
        self._updateRange(self.root, i, j, val)

    def _updateRange(self, root, i, j, val):
        start, end = root.start, root.end
        if i == start and j == end:
            root.val = val
            root.lazyVal = val
            return

        # 当node的lazyVal不为空的时候，需要将缓存的lazy值下推给子node
        if root.lazyVal is not None:
            self._pushDown(root)

        mid = (start + end) // 2
        if j <= mid:
            self._updateRange(root.left, i, j, val)
        elif i >= mid+1:
            self._updateRange(root.right, i, j, val)
        else:
            self._updateRange(root.left, i, mid, val)
            self._updateRange(root.right, mid+1, j, val)

    def getRange(self, i, j):
        return self._getRange(self.root, i, j)

    def _getRange(self, root, i, j):
        start, end = root.start, root.end
        if i == start and j == end:
            return root.val
        
        # 当node的lazyVal不为空的时候，需要将缓存的lazy值下推给子node
        if root.lazyVal is not None:
            self._pushDown(root)
        
        mid = (start + end) // 2
        if j <= mid:
            return self._getRange(root.left, i, j)
        if i >= mid+1:
            return self._getRange(root.right, i, j)
        return max(self._getRange(root.left, i, mid), self._getRange(root.right, mid+1, j))

    def _pushDown(self, root):
        if root.left:
            root.left.val = root.lazyVal
            root.left.lazyVal = root.lazyVal
        if root.right:
            root.right.val = root.lazyVal
            root.right.lazyVal = root.lazyVal
        root.lazyVal = None

```