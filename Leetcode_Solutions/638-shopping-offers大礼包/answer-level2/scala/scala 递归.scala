```scala
import scala.collection.mutable.ListBuffer

object Solution {
  def shoppingOffers(price: List[Int], special: List[List[Int]], needs: List[Int]): Int = {
    var res = 0
    val t = new ListBuffer[Int]
    needs.indices.foreach(i => t.append(needs(i)))
    price.indices.foreach(i => res += price(i) * t(i))
    special.foreach(i => {
      var flag = true
      price.indices.foreach(j => {
        if (t(j) - i(j) < 0) flag = false
        t(j) -= i(j)
      })
      if (flag) res = res.min(shoppingOffers(price, special, t.toList) + i.last)
      price.indices.foreach(j => t(j) += i(j))
    })
    res
  }
}
```
