```
object Solution {
  var isMapReady: Boolean = false
  val mymap = scala.collection.mutable.Map[Char, List[Int]]()

  def fillMap(t: String): Unit = {
    for (i <- 0 to t.length - 1) {
      val index = t.length - 1 - i
      if (mymap.contains(t(index))) {
        mymap(t(index)) = index :: mymap(t(index))
      } else {
        mymap(t(index)) = index :: Nil
      }
    }
    isMapReady = true
  }

  def isSubsequence(s: String, t: String): Boolean = {
    mymap.clear() // 假设传递的t相同， 此处无需执行此操作 根据isMapReady判断可以避免多次填充mymap 
    fillMap(t)
    var curPosition = -1
    for (item <- s) {
      if (mymap.contains(item)) {
        val ints: List[Int] = mymap(item)
        val maybeInt: Option[Int] = ints.find(_ > curPosition)
        if (maybeInt.isDefined) {
          curPosition = maybeInt.get
        } else {
          return false
        }
      } else {
        return false
      }
    }
    return true
  }

  //var i = 0
  //var j = 0
  //while (j < t.size && i < s.size) {
  //if (t(j) == s(i)) {
  //i += 1
  //j += 1
  //} else {
  //j += 1
  //}
  //}
  //if (i == s.size) return true else false
}

//leetcode submit region end(Prohibit modification and deletion)

```
