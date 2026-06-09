### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def peakIndexInMountainArray(A: Array[Int]): Int = {
        A.indexOf(A.max)
    }
}
```