```
class Solution {

    fun nthUglyNumber(n: Int): Int {
        if (n == 1) {
            return 1
        }

        /** 去重用的 */
        val set = hashSetOf<Int>()
        /** 排序用的 */
        val queue = LinkedList<Int>()
        queue.add(1)
        set.add(1)

        /** 针对三个因子，三个索引 */
        var a = 0
        var b = 0
        var c = 0

        while (queue.size < n) {
            val valueA = queue[a] * 2
            val valueB = queue[b] * 3
            val valueC = queue[c] * 5
            val min = Math.min(Math.min(valueA, valueB), valueC)
            if (!set.contains(min)) {
                queue.offer(min)
                set.add(min)
            }
            when {
                valueA == min -> a ++
                valueB == min -> b ++
                else -> c ++
            }
        }

        return queue.last
    }

}
```
