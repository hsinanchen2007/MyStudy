```
class MyHashMap() {
  class Bucket {
    var list = List[(Int, Int)]()
    def get(key: Int): Int = {
      val maybeTuple: Option[(Int, Int)] = list.find(_._1 == key)
      if (maybeTuple.isDefined) maybeTuple.get._2 else -1
    }
    def put(elem: (Int, Int)) = {
      val toBeDelete = list.filter(_._1 == elem._1)
      val tmp = list diff toBeDelete
      list = elem :: list
    }
    def remove(key: Int) = {
      val toBeDelete = list.filter(_._1 == key)
      list = list.filter(_._1 != key)
    }
    def contains(key: Int) = {
      list.map(_._1).contains(key)
    }
  }
  /** Initialize your data structure here. */
  val base = 765
  val arr = new Array[Bucket](base)
  for (i <- 0 to arr.length - 1) {
    arr(i) = new Bucket
  }
  /** value will always be non-negative. */
  def put(key: Int, value: Int) {
    val idx = key % base
    arr(idx).put((key, value))
  }
  /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
  def get(key: Int): Int = {
    val idx = key % base
    arr(idx).get(key)
  }
  /** Removes the mapping of the specified value key if this map contains a mapping for the key */
  def remove(key: Int) {
    val idx = key % base
    arr(idx).remove(key)
  }
}

```
