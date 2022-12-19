```
fun oddCells(n: Int, m: Int, indices: Array<IntArray>): Int {
    var oddNumCount = 0
    for (array in indices) {
        val ri = array[0]
        val ci = array[1]

    }
    for (i in 0 until n) {
        var index = 0
        for (j in 0 until m) {
            var value = 0
            indices.forEach {
                if (it[0] == i) {
                    value += 1
                }
                if (it[1] == j) {
                    value += 1
                }
            }
            if (value % 2 != 0) oddNumCount++
        }
    }
    return oddNumCount
}
```
