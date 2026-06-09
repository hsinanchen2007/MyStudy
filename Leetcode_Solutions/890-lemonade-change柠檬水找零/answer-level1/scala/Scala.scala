### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def lemonadeChange(bills: Array[Int]): Boolean = {
    if (bills(0) != 5 || bills(1) > 10) return false
    var five, ten = 0
    for (res <- bills) {
      res match {
        case _ if five < 0 => return false
        case 5 => five += 1
        case 10 => ten += 1
          five -= 1
        case _ if ten > 0 => ten -= 1
          five -= 1
        case _ => five -= 3
      }
    }
    five > -1 
    }
}
```