到每一个结点的花费都等于走到它左边或者右边的节点的花费, 加上它的值
在原有数组的基础上改变每一个点, 不需要额外空间, 修改后每一个数字的值就是从起始到它的左小步数

```kotlin
 fun minPathSum(grid: Array<IntArray>): Int{
        //两层循环分别控制层数和位数
        for (i in grid.indices) {
            for (j in grid[0].indices) {//因为每一层数量一样, 所以j就以第初层数组的下标遍历
                if (i == 0 && j == 0) continue //第一个
                else if (i == 0) //第一排的, 上一步只能是右行
                    grid[i][j] += grid[i][j - 1]
                else if (j == 0) //第一列的, 上一步只能是下行
                    grid[i][j] += grid[i - 1][j]
                else //选择其上或左中较小的那个
                    grid[i][j] += grid[i - 1][j].coerceAtMost(grid[i][j - 1])
            }
        }
        return grid[grid.size - 1][grid[0].size - 1]
    }
```