### 解题思路
判断A是否和排好序的A或者排好序的A的反转一样

### 代码

```scala
object Solution {
    def isMonotonic(A: Array[Int]): Boolean = {
    if ((A.sorted sameElements A) || (A sameElements A.sorted.reverse))
      return true
    false    
    }
}
```