```scala []
object Solution {
    def topKFrequent(A: Array[Int], k: Int): List[Int] = {
        A
        .groupBy{x => x}
        .toList
        .sortBy{case (k, v) => - v.length}
        .take(k)
        .map{case(k,v) => k}
    }
}

```