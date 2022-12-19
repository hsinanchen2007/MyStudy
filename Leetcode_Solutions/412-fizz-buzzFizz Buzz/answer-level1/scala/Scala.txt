### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def fizzBuzz(n: Int): List[String] = {
        import scala.collection.mutable.ListBuffer
     var list = new ListBuffer[String]
    for (i <- 1 to n) {
      if (i % 3 == 0 && i % 5 != 0)
        list += "Fizz"
      if (i % 5 == 0 && i % 3 != 0)
        list += "Buzz"
      if (i % 3 == 0 && i % 5 == 0)
        list += "FizzBuzz"
      if (i % 3 != 0 && i % 5 != 0)
        list += i.toString

    }
    list.toList   
    }
}
```