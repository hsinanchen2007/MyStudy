```
object Solution {
  def licenseKeyFormatting(S: String, K: Int): String = {
    var num = 0
    var l = List[Char]()
    for (item <- S.reverse) {
      if (item == '-') {
        println("- dropped! ")
      } else {
        l = item.toUpper :: l
        num += 1
        if (num == K) {
          l = '-' :: l
          num = 0
        }
      }
    }
    val ret = l match {
      case h :: t if (h == '-') => t
      case ll => ll
    }
    ret.mkString
  }
}

```
