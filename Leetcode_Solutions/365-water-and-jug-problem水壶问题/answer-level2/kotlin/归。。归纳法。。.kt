观察题目给的两个例子：

```plain
3,5,4
3,5     <- 先装满水
0,5     <- 然后把小水壶的水倒掉
3,2     <- 用大水壶的水装给小水壶
0,2     <- 倒掉小水壶的水
2,0     <- 再用大水壶装给小水壶
2,5     <- 大水壶空了，装满
3,4     <- 再装给小水壶

2,6,5
2,6
0,6
2,4
0,4
2,2
0,2
2,0
0,0
```

这个规律是我随意尝试的时候发现的。。即总可以通过**大水壶只装水**以及**小水壶只倒水**两种行动来判断能否有解，其实已经有点类似所谓的祖尔定律了。

最后贴代码：

```kotlin
class Solution {
    fun canMeasureWater(x: Int, y: Int, z: Int): Boolean {
        // 不需要装任何水，即 true
        if (z == 0) {
            return true
        }
        // assert: x < y
        if (x > y) {
            return canMeasureWater(y, x, z)
        }
        // 如果 x == 0，且 z != 0，那么能否装满取决于 y 和 z 的关系
        if (x == 0) {
            return y == z
        }

        // 初始状态：小的水壶和大的水壶均装满水
        var (cx, cy) = x to y
        while (cx != 0 || cy != 0) {
            when {
                // 状态 0：大水壶或大小水壶之和满足了题意
                cy == z || cx + cy == z -> {
                    return true
                }
                // 状态 1：用大水壶的水持续给小水壶装水，直到小水壶满或大水壶空
                cx != x && cy > 0 -> {
                    val needFill = x - cx
                    val actualFill = if (needFill <= cy) needFill else cy
                    cx += actualFill; cy -= actualFill
                }
                // 状态 2：小水壶满了，清空
                cx == x -> {
                    cx = 0
                }
                // 状态 3：大水壶空了，加满
                cy == 0 -> {
                    cy = y
                }
            }
        }

        // cx == 0 && cy == 0，无解
        return false
    }
}
```
