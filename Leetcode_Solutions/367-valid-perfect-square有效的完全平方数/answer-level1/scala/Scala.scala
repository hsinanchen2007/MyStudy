### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def isPerfectSquare(num: Int): Boolean = {
    if (num < 2) return true
    var res = 0
    while (res < num) {
      if (num == res * res) {
        return true
      } else {
        res += 1
      }
    }
    false    
    }
}
```