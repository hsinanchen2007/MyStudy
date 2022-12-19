```
object Solution {
  def fizzBuzz(n: Int): List[String] = {
    var l: List[String] = List()
    for (i <- (1 to n).reverse) {
      if (i % 3 == 0 && i % 5 == 0) {
        l = "FizzBuzz" :: l
      } else if (i % 3 == 0) {
        l = "Fizz" :: l
      } else if (i % 5 == 0) {
        l = "Buzz" :: l
      } else {
        l = i.toString :: l
      }
    }
    l
  }
}
```
