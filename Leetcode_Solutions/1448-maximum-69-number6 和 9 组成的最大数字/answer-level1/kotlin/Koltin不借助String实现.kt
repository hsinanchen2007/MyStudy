Kotlin从个位依次遍历，发现6加上对应的30(后面0的个数即遍历次数), 求最大即可
```kotlin
class Solution {
    fun maximum69Number(num: Int): Int {
        var backup = num
        var add = 3

        var max = num
        while (backup > 0) {
            if (backup % 10 == 6) {
                max = Math.max(num + add, max)
            }
            backup /= 10
            add *= 10
        }

        return max
    }
}
```
