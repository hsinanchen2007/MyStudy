```scala
object Solution {
  def findRadius(houses: Array[Int], heaters: Array[Int]): Int = {
    var j = 0
    var res = 0
    val house = houses.sorted
    val heater = heaters.sorted
    house.indices.foreach(i => {
      val cur = house(i)
      while (j < (heater.length - 1) && math.abs(heater(j + 1) - cur) <= math.abs(heater(j) - cur)) j += 1
      res = res.max(math.abs(heater(j) - cur))
    })
    res
  }
}
```
