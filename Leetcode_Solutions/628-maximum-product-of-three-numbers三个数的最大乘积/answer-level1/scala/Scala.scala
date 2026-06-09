### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def maximumProduct(nums: Array[Int]): Int = {
    val num = nums.sorted
    val l = num.length - 1
    math.max(num(l) * num(l - 1) * num(l - 2), num(0) * num(1) * num(l)) 
    }
}
```