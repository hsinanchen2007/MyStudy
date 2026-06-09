```scala []
object Solution {
    def isReflected(points: Array[Array[Int]]): Boolean = {
        def f(points: Array[Array[Int]]): Boolean = {
            val x_mean = points.map{case Array(x,y) => x}.sum.toDouble / points.length
            val table = scala.collection.mutable.HashMap[Double, Int]()
            points foreach {case Array(x,y) => table.put(x - x_mean, y)}
            points.forall {case Array(x,y) => 
                table.contains(x_mean - x) && 
                table(x - x_mean) == table(x_mean - x)}
        }
        f(points.map(_.toList).distinct.map(_.toArray))
    }
}
```

```
