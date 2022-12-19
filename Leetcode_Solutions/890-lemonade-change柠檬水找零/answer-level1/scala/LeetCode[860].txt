```
object Solution {
  def lemonadeChange(bills: Array[Int]): Boolean = {
    val mymap = scala.collection.mutable.Map[Int, Int]()
    mymap(5) = 0
    mymap(10) = 0
    mymap(20) = 0
    for (item <- bills) {
      if (item == 5) {
        mymap(5) += 1
      } else if (item == 10) {
        if (mymap(5) >= 1) {
          mymap(10) += 1
          mymap(5) -= 1
        } else {
          return false
        }
      } else if (item == 20) {
        if (mymap(10) >= 1 && mymap(5) >= 1) {
          mymap(20) += 1
          mymap(10) -= 1
          mymap(5) -= 1
        } else if (mymap(10) == 0 && mymap(5) >= 3) {
          mymap(20) += 1
          mymap(5) -= 3
        } else {
          return false
        }
      }
    }
    return true
  }
}

```
