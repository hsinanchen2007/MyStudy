### 解题思路
构造一棵2维线段树即可得解。

图解：
![2维线段树.001.jpeg](https://pic.leetcode-cn.com/f03bbaee310aea37367f94894413967c679a77d23c8e8df24ec8d08d362a61fd-2%E7%BB%B4%E7%BA%BF%E6%AE%B5%E6%A0%91.001.jpeg)

易错点：
1. node的上下左右边界有可能不合法
2. 每一个node未必都有四个子node，每次node对应的区间矩阵和应当清零后，根据子node的有无进行重新计算
3. 求区间矩阵和的时候，上下左右边界要收缩至不能收缩

### 代码

```
class Node:
    def __init__(self, topIndex, bottomIndex, leftIndex, rightIndex, val):
        self.topIndex = topIndex
        self.bottomIndex = bottomIndex
        self.leftIndex = leftIndex
        self.rightIndex = rightIndex
        self.val = val
        self.leftTop = None
        self.rightTop = None
        self.leftBottom = None
        self.rightBottom = None

class SegmentTree2D:
    def __init__(self, matrix):
        self.matrix = matrix
        n = len(self.matrix)
        if n == 0:
            return
        m = len(self.matrix[0])
        if m == 0:
            return
        self.root = self._buildTree(0, n-1, 0, m-1)

    def _buildTree(self, topIndex, bottomIndex, leftIndex, rightIndex):
        # 判断上下左右边界是否合法
        if topIndex > bottomIndex or leftIndex > rightIndex:
            return None
        if topIndex == bottomIndex and leftIndex == rightIndex:
            return Node(topIndex, bottomIndex, leftIndex, rightIndex, self.matrix[topIndex][leftIndex])

        root = Node(topIndex, bottomIndex, leftIndex, rightIndex, 0)
        rowMid = (topIndex + bottomIndex) // 2
        colMid = (leftIndex + rightIndex) // 2
        root.leftTop = self._buildTree(topIndex, rowMid, leftIndex, colMid)
        root.rightTop = self._buildTree(topIndex, rowMid, colMid+1, rightIndex)
        root.leftBottom = self._buildTree(rowMid+1, bottomIndex, leftIndex, colMid)
        root.rightBottom = self._buildTree(rowMid+1, bottomIndex, colMid+1, rightIndex)
        # 子node的值被设定后，即可计算出node所代表的矩阵和
        if root.leftTop:
            root.val += root.leftTop.val
        if root.rightTop:
            root.val += root.rightTop.val
        if root.leftBottom:
            root.val += root.leftBottom.val
        if root.rightBottom:
            root.val += root.rightBottom.val
        return root

    def update(self, row, col, val):
        self._update(self.root, row, col, val)

    def _update(self, root, row, col, val):
        if root.topIndex == root.bottomIndex == row and root.leftIndex == root.rightIndex == col:
            root.val = val
            return
        rowMid = (root.topIndex + root.bottomIndex) // 2
        colMid = (root.leftIndex + root.rightIndex) // 2
        if row <= rowMid and col <= colMid:
            self._update(root.leftTop, row, col, val)
        elif row <= rowMid and col >= colMid+1:
            self._update(root.rightTop, row, col, val)
        elif row >= rowMid+1 and col <= colMid:
            self._update(root.leftBottom, row, col, val)
        else:
            self._update(root.rightBottom, row, col, val)
        # 子node的矩阵和被更新后，node所代表的矩阵和也需要清零，重新计算
        root.val = 0
        if root.leftTop:
            root.val += root.leftTop.val
        if root.rightTop:
            root.val += root.rightTop.val
        if root.leftBottom:
            root.val += root.leftBottom.val
        if root.rightBottom:
            root.val += root.rightBottom.val

    def getRegion(self, row1, col1, row2, col2):
        return self._getRegion(self.root, row1, col1, row2, col2)

    def _getRegion(self, root, row1, col1, row2, col2):
        if root.topIndex == row1 and root.bottomIndex == row2 and root.leftIndex == col1 and root.rightIndex == col2:
            return root.val
        rowMid = (root.topIndex + root.bottomIndex) // 2
        colMid = (root.leftIndex + root.rightIndex) // 2
        regionSum = 0
        # 注意收缩上下左右边界
        if row1 <= rowMid and col1 <= colMid:
            regionSum += self._getRegion(root.leftTop, row1, col1, min(rowMid, row2), min(colMid, col2))
        if row1 <= rowMid and col2 >= colMid+1:
            regionSum += self._getRegion(root.rightTop, row1, max(colMid+1, col1), min(rowMid, row2), col2)
        if row2 >= rowMid+1 and col1 <= colMid:
            regionSum += self._getRegion(root.leftBottom, max(rowMid+1, row1), col1, row2, min(colMid, col2))
        if row2 >= rowMid+1 and col2 >= colMid+1:
            regionSum += self._getRegion(root.rightBottom, max(rowMid+1, row1), max(colMid+1, col1), row2, col2)
        return regionSum


class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.segmentTree2D = SegmentTree2D(matrix)
        
    def update(self, row: int, col: int, val: int) -> None:
        self.segmentTree2D.update(row, col, val)

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return self.segmentTree2D.getRegion(row1, col1, row2, col2)
        

# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# obj.update(row,col,val)
# param_2 = obj.sumRegion(row1,col1,row2,col2)
```