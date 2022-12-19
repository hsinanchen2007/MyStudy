
```scala []
object Solution {
    def mostVisitedPattern(username: Array[String], timestamp: Array[Int], website: Array[String]): Array[String] = {
        val webs = website.distinct
        val table = scala.collection.mutable.HashMap[String, Int]()
        webs.zipWithIndex foreach {case (x, i) => table.put(x, i)}
        val n = webs.length
        val dp = Array.fill(n, n,n)(0)
        
        (username zip timestamp zip website)
        .map{case ((x,y), z) => (x,y,z)}
        .groupBy{case (x,y,z) => x}
        .values
        .toList
        .filter{vec => vec.length >= 3}
        .map{vec => vec.sortBy{case (x,y,z) => y}} foreach { vec => 
            var l = List.empty[(Int, Int, Int)]
            for{
                i <- vec.indices
                j <- i+1 until vec.length
                k <- j+1 until vec.length
            }
            l ::= (table(vec(i)._3), table(vec(j)._3), table(vec(k)._3))
            l.distinct foreach {case (i,j,k) => dp(i)(j)(k) += 1}
        }
        
        var m = 0
        for{
            i <- 0 until n
            j <- 0 until n
            k <- 0 until n
            if dp(i)(j)(k) > m 
        } m = dp(i)(j)(k)
        
        (for{
            i <- 0 until n
            j <- 0 until n
            k <- 0 until n
            if dp(i)(j)(k) == m
        } yield Array(webs(i), webs(j), webs(k))).sortBy{case Array(x,y,z) => (x,y,z)}.head
        
    }
}
```


```
