### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def findComplement(num: Int): Int = {
      val l = num.toBinaryString.length
    num ^ (math.pow(2, l) - 1).toInt  
    }
}
```