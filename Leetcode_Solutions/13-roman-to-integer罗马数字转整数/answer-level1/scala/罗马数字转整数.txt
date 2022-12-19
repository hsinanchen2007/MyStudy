这个其实就是一个map查找,别的没啥,先找2位的,找不到,再改成找1位的

```
object Solution {
  def romanToInt(s: String): Int = {
    val map = Map(
      "I" -> 1,
      "V" -> 5,
      "X" -> 10,
      "L" -> 50,
      "C" -> 100,
      "D" -> 500,
      "M" -> 1000,
      "IV" -> 4,
      "IX" -> 9,
      "XL" -> 40,
      "XC" -> 90,
      "CD" -> 400,
      "CM" -> 900
    )
    val buffer = scala.collection.mutable.ArrayBuffer[Int]()
    var i = 0
    val ss=s+"1"
    while (i < ss.length-1) {
      val roman2 = ss.slice(i, i + 2)
      if (map.contains(roman2)) {
        buffer += map(roman2)
        i += 2
      } else {
        buffer += map(ss(i).toString)
        i += 1
      }
    }

    buffer.sum
  }
}

```
