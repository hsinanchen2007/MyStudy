```scala
import scala.collection.mutable

class AllOne() {

  /** Initialize your data structure here. */

  var max_value: Option[Int] = None
  var min_value: Option[Int] = None
  private val m = mutable.HashMap[String, Int]()
  private val v = mutable.HashMap[Int, Set[String]]()

  /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
  def inc(key: String): Unit = {
    m.put(key, 1 + (m getOrElse(key, 0)))
    if (m(key) == 1) {
      max_value match {
        case None =>
          max_value = Some(1)
          v.put(1, Set(key))
        case Some(_) =>
      }
      min_value match {
        case None =>
          min_value = Some(1)
        case Some(_) => min_value = Some(1)
      }
      v.put(1, v.getOrElse(1, Set.empty[String]) + key)
    } else {
      v.put(m(key) - 1, v(m(key) - 1) - key)
      if (v(m(key) - 1).isEmpty) v -= m(key) - 1
      v.put(m(key), v.getOrElse(m(key), Set.empty[String]) + key)
      if (m(key) > max_value.get) max_value = Some(m(key))
      if (m(key) - 1 == min_value.get) {
        if (!v.contains(m(key) - 1)) {
          min_value = Some(m(key))
        }
      }
    }
  }

  /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
  def dec(key: String) {
    if (!m.contains(key)) return
    m.put(key, -1 + (m getOrElse(key, 0)))
    if (m(key) <= 0) m -= key
    if (m.contains(key)) {
      v.put(m(key) + 1, v(m(key) + 1) - key)
      if (v(m(key) + 1).isEmpty) v -= (m(key) + 1)

      v.put(m(key), v.getOrElse(m(key), Set.empty[String]) + key)
      if (max_value.get == m(key) + 1 && !v.contains(m(key) + 1)) max_value = Some(m(key))
      if (m(key) < min_value.get) min_value = Some(m(key))

    } else {
      v.put(1, v(1) - key)
      if (v(1).isEmpty) v - 1

      if (max_value.get == 1 && v(1).isEmpty) max_value = None
      if (v(1).isEmpty) min_value = v.keySet.filter(i => v(i).nonEmpty).toList.sorted.headOption
    }
  }

  /** Returns one of the keys with maximal value. */
  def getMaxKey(): String = {
    max_value match {
      case Some(i) => v(i).head
      case None => ""
    }
  }

  /** Returns one of the keys with Minimal value. */
  def getMinKey(): String = {
    min_value match {
      case Some(i) => v(i).head
      case None => ""
    }
  }

}
```
