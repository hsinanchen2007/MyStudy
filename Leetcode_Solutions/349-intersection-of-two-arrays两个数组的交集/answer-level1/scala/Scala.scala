### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def intersection(nums1: Array[Int], nums2: Array[Int]): Array[Int] = {
    import scala.collection.mutable.ArrayBuffer
       val A = new ArrayBuffer[Int]()
    for (res <- nums2) {
      if (nums1.contains(res)) {
        A += res
      }
    }
    A.distinct.toArray
    }
}
```