### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def uniqueOccurrences(arr: Array[Int]): Boolean = {  
    import scala.collection.mutable
    val map = new mutable.HashMap[Int, Int]
    for (i <- arr) {
      if (map.contains(i)) {
        var integer = map(i)
        integer += 1
        map.put(i, integer)
      } else {
        map.put(i, 1)
      }
    }
    val hashSet = new mutable.HashSet[Int]()
    for ((k, v) <- map) {
      if(map.contains(k))
      hashSet.add(v)
    }
    map.size == hashSet.size    
    }
}
```