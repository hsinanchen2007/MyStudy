__整体采用构建矩阵，填充矩阵的思路，填充过程分为四种情况：__
1. 从左到右填充一行
1. 从上到下填充一列
1. 从右到左填充一行，注意只有一行的情况
1. 从下到上填充一列，注意只有一列的情况

__详细逻辑可以参考代码注释__
```Scala []
object Solution {
    def generateMatrix(n: Int): Array[Array[Int]] = {
        // 构建矩阵
        val resultMatrix = new Array[Array[Int]](n)
        (0 until n).foreach { index =>
          resultMatrix(index) = new Array[Int](n)
        }

        // 计算结果值
        val resultNum = n * n

        // 填充矩阵
        var rowBegin = 0
        var rowEnd = n - 1
        var columnBegin = 0
        var columnEnd = n - 1
        var insertNum = 1
        while (insertNum <= resultNum) {
          // 填充矩阵的上边，从左到右填充一行
          // 每次循环行不变，列加一。并且循环结束后行加一
          var columnTemp = columnBegin
          while (columnTemp <= columnEnd) {
            resultMatrix(rowBegin)(columnTemp) = insertNum
            insertNum += 1
            columnTemp += 1
          }
          rowBegin += 1

          // 填充矩阵的右边，从上到下填充一列
          // 每次循环列不变，行加一。并且循环结束后列减一
          var rowTemp = rowBegin
          while (rowTemp <= rowEnd) {
            resultMatrix(rowTemp)(columnEnd) = insertNum
            insertNum += 1
            rowTemp += 1
          }
          columnEnd -= 1

          // 填充矩阵下边，从右到左填充一行（注意只有一行的情况）
          // 每次循环行不变，列减一。并且循环结束后行加一
          columnTemp = columnEnd
          while (columnTemp >= columnBegin && rowEnd >= rowBegin) {
            resultMatrix(rowEnd)(columnTemp) = insertNum
            insertNum += 1
            columnTemp -= 1
          }
          rowEnd -= 1

          // 填充矩阵左边，从下到上填充一列（注意只有一列的情况）
          // 每次循环列不变，行加一。并且循环结束后列加一
          rowTemp = rowEnd
          while (rowTemp >= rowBegin && columnEnd >= columnBegin) {
            resultMatrix(rowTemp)(columnBegin) = insertNum
            insertNum += 1
            rowTemp -= 1
          }
          columnBegin += 1
        }

        resultMatrix
    }
}
```
__复杂度分析__

- 时间复杂度：$O(n^2)$
  
  我们填充时遍历一次矩阵，矩阵元素个数为 $n^2$（其中 $n$ 为参数），所以时间复杂度为 $n^2$
- 空间复杂度：$O(n^2)$
  
  需要一个矩阵 `resultMatrix` 存储结果