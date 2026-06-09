一个可行的解法, 可惜会超出内存限制! 

```
    fun maxNumberOfFamilies(n: Int, reservedSeats: Array<IntArray>): Int {
        val matrix = Array(reservedSeats.size) { IntArray(10) { 0 } }
        var x = 0
        var y = 0
        for (i in reservedSeats.indices) {
            x = reservedSeats[i][0] - 1
            y = reservedSeats[i][1] - 1
            matrix[x][y] = -1
        }
        var count = 0
        var a = true
        var b = true
        var c = true
        var d = true
        for (i in matrix.indices) {
            a = true
            b = true
            c = true
            d = true
            for (j in 0..9) {
                if (matrix[i][j] == -1) {
                    if (j in 1..2) {
                        a = false
                    } else if (j in 3..4) {
                        b = false
                    } else if (j in 5..6) {
                        c = false
                    } else if (j in 7..8) {
                        d = false
                    }
                }
            }
            println("$a, $b, $c, $d")
            if (a && b && c && d) {
                count += 2
                continue
            } else if (a && b && c) {
                count++
                continue
            } else if (b && c && d) {
                count++
                continue
            } else if (a && b) {
                continue
                count++
            } else if (b && c) {
                continue
                count++
            } else if (c && d) {
                continue
                count++
            }
        }
        return count
    }
```
