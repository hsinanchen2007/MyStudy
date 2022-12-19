```
class MyHashSet() {
  /** Initialize your data structure here. */
  var base = 765
  val arr = new Array[Bucket](base)
  for (i <- 0 to arr.length - 1) {
    arr(i) = new Bucket
  }
  private def hash(key: Int): Int = {
    key % base
  }
  def add(key: Int) {
    val idx = key % base
    arr(idx).insert(key)
  }
  def remove(key: Int) {
    val idx = key % base
    arr(idx).delete(key)
  }
  /** Returns true if this set contains the specified element */
  def contains(key: Int): Boolean = {
    val idx = key % base
    arr(idx).contains(key)
  }
  class Bucket {
    var list = List[Int]()
    def insert(elem: Int) = {
      list = elem :: list
    }
    def delete(elem: Int) = {
      list = list.filter(_!=elem)
    }
    def contains(elem: Int) = list.contains(elem)
  }
}
```
