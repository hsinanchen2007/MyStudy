```scala
object Solution {
  def intToRoman(num: Int): String = {
    val v1: Array[String] = Array[String]("", "M", "MM", "MMM")
    val v2: Array[String] = Array[String]("", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM")
    val v3: Array[String] = Array[String]("", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC")
    val v4: Array[String] = Array[String]("", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX")
    v1(num / 1000) + v2((num % 1000) / 100) + v3((num % 100) / 10) + v4(num % 10)
  }
}
```
