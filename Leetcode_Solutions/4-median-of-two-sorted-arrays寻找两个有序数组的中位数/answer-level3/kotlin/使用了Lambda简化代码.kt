### 解题思路
已知中位数算法
``` kotlin
val median: (IntArray) -> Double = {
    if (it.size % 2 == 0) {
        (it[it.size / 2 - 1] + it[it.size / 2]) / 2.0
    } else {
        it[it.size / 2].toDouble()
    }
}
```

按题目的要求应该是合并两个有序数组，然后求中位数，因为是有序数组，合并算法复杂度为O(m+n)，方法就是两个数组交替填充。算法本身不复杂，需要处理的特殊情况比较多，使用了Lambda简化了代码。

### 代码

```kotlin
class Solution {
    fun findMedianSortedArrays(nums1: IntArray, nums2: IntArray): Double {
        val median: (IntArray) -> Double = {
            if (it.size % 2 == 0) {
                (it[it.size / 2 - 1] + it[it.size / 2]) / 2.0
            } else {
                it[it.size / 2].toDouble()
            }
        }

        if (nums1.isEmpty()) {
            return median(nums2)
        }
        if (nums2.isEmpty()) {
            return median(nums1)
        }

        var i1 = 0
        var i2 = 0

        val array = IntArray(nums1.size + nums2.size)
        val first = if (nums1.first() < nums2.first()) {
            i1 = 1
            nums1.first()
        } else {
            i2 = 1
            nums2.first()
        }

        array[0] = first
        var i = 1
        while (i < array.size) {
            if (i1 > nums1.size - 1 && i2 < nums2.size) {
                array[i] = nums2[i2]
                i2++
                i++
                continue
            }
            if (i2 > nums2.size - 1 && i1 < nums1.size) {
                array[i] = nums1[i1]
                i1++
                i++
                continue
            }

            if (nums1[i1] <= nums2[i2]) {
                array[i] = nums1[i1]
                i1++
            } else {
                array[i] = nums2[i2]
                i2++
            }
            i++
        }
        return median(array)
    }
}
```