### 解题思路
此处撰写解题思路

### 代码

```kotlin
class Solution {
    fun generateMatrix(n: Int): Array<IntArray> {
        var result = ArrayList<IntArray>(n)
        for (i in 0 until n) {
            var array = IntArray(n)
            result.add(array)
        }
        var x = 0
        var y = 0
        var cycle = 0
        var num = 1
        while (true) {
            //(0,0) -> (0,n)
            for (i in cycle until n - cycle) {
                result[cycle][i] = num++
            }
            x = n - cycle - 1
            if (y + 1 >= n - cycle) {
                break
            }

            //(0,n) -> (n,n)
            for (i in cycle + 1 until n - cycle) {
                result[i][x] = num++
            }
            y = n - cycle - 1
            if (x - 1 < cycle) {
                break
            }

            //(n,n) -> (n,0)
            for (i in x - 1 downTo cycle) {
                result[y][i] = num++
            }
            x = cycle
            if (y - 1 < cycle) {
                break
            }

            //(n,0) -> (cycle+1,0)
            for (i in y - 1 downTo cycle + 1) {
                result[i][x] = num++
            }
            y = cycle + 1
            if (x + 1 >= n - cycle) {
                break
            }

            cycle++
        }
        return result.toTypedArray()
    }
}
```