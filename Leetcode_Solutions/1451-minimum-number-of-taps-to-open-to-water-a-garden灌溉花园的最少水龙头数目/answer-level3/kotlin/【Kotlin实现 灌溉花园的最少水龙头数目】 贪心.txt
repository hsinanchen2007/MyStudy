## 观察题目
1. 首先看到数据范围是 1 <= n <= 10^4，因此可以复杂度使用O(n²)没有问题
2. 花园必须要都灌溉到，因此只要有一处浇不到就可以return -1

### 解法一 暴力贪心
1. 设置p为 当前必须要被浇到的点（即p之前已经被浇到了，从0开始）
2. q为覆盖到当前浇到的点的水龙头能到达的最远距离
3. 每次循环完成，将q赋值给p（注意，这里是需要连续的，即浇【4, 6】后必须要【6, n】而不能【7, n】，因为【6, 7】之间的土地部分，我们浇的不是点而是连续的线段）
4. 如果p走到了 >= n，代表当前选择的数量已足够覆盖到整个花园，直接return即可
5. 如果某次循环p == q，代表当前已经没有进步空间了...下一段没有任何水龙头能浇到，因此直接return -1
6. 时间复杂度为 **O(n²)**，比较暴力的解法，第二层for循环是从0到n的
```kotlin []
fun minTaps(n: Int, ranges: IntArray): Int {
    var p = 0
    var q = 0
    var res = 0
    while (p < n) {
        for (i in 0..n) {
            if (i - ranges[i] <= p) {
                q = maxOf(q, i + ranges[i])
            }
        }
        if (p == q) return -1
        p = q
        res++
    }
    return res
}
```

### 解法二 优化贪心
1. 上面的解法是双层for循环完整遍历，如果对原始数据进行排序，可以只遍历一次
2. 首先将每个点能覆盖到的范围计算出intervals列表
3. 按照左侧进行排序，遍历的时候只需要一遍即可
4. 内部原理与上述相同，cur代表当前必须被浇灌到的点，next为当前覆盖cur的同时能够覆盖最远的点
5. 时间复杂度 为 **O(nlogn)**
```kotlin []
fun minTaps(n: Int, ranges: IntArray): Int {
    val intervals = ArrayList<Pair<Int, Int>>()
    for (i in 0..n) {
        intervals.add(Pair(i - ranges[i], i + ranges[i]))
    }
    intervals.sortBy { it.first }
    var ans = 0
    var cur = 0
    var next = 0
    var index = 0
    while (index <= n) {
        val it = intervals[index]
        if (it.first <= cur) {
            next = maxOf(next, it.second)
            index++
            if (next >= n) {
                return ans + 1
            }
        } else {
            if (next == cur) {
                return -1
            }
            cur = next
            ans++
        }
    }
    return ans
}
```
