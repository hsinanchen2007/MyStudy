### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def isUgly(num: Int): Boolean = {
     var nums: Int = num
     if (nums == 0) return false
    if (nums == 1) return true
    while (nums % 5 == 0) {
      nums /= 5
    }
    while (nums % 3 == 0) {
      nums /= 3
    }
    while (nums % 2 == 0) {
      nums /= 2
    }
    if (nums == 1) return true
    false
    }
}
```