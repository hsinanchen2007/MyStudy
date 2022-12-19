```scala []
object Solution {
    def findRelativeRanks(A: Array[Int]): Array[String] = {
        val rank = scala.collection.mutable.HashMap[Int,Int]()
        A.sortBy(-_).zipWithIndex foreach {case (x, i) => rank.put(x, i)}
        A map rank map inc map f
    }
    def inc(x:Int):Int = x + 1
    def f(rank:Int):String = rank match {
        case 1 => "Gold Medal"
        case 2 => "Silver Medal"
        case 3 => "Bronze Medal"
        case _ => rank.toString
    }
}
```

