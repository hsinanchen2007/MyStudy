1,最基础的做法,暴力算法,计算每一个开始位置的不重复的长度,用一个set做判断
```
import scala.collection.mutable
object Solution {
  def lengthOfLongestSubstring(s: String): Int = {
    var m = 0
    val len = s.length
    for (i <- s.indices) {
      var j = i
      val a = mutable.HashSet[Char]()
      var c = 0
      while (j < len && !a.contains(s(j))) {
        a += s(j)
        c += 1
        j += 1
      }
      m = m.max(c)
    }
    m
  }
}
```
2,看讨论,大家都说滑动窗口,根据这个思想,用队列实现如下
```

object Solution {
  def lengthOfLongestSubstring(s: String): Int = {
    var m = 0
    val q = scala.collection.mutable.Queue[Char]()
    val a = scala.collection.mutable.HashSet[Char]()
    for (c <- s) {
      if (!a.contains(c)) {
        q.enqueue(c)
        a += c
      } else {
        m = m.max(q.length)
        var flag = true
        while (flag) {
          val t = q.dequeue()
          a -= t
          if (t == c) {
            flag = false
          }
        }
        q.enqueue(c)
        a += c
      }
    }
    m = m.max(q.length)
    m
  }
}


```

3,这个滑动窗口,除了用队列实现,也可以用hashmap实现,思想完全一样
```
object Solution {
  def lengthOfLongestSubstring(s: String): Int = {
    var m = 0
    val len = s.length
    val map = scala.collection.mutable.HashMap[Char, Int]()
    var start = 0
    var end = 0
    while (end < len) {
      val c = s(end)
      if (map.contains(c)) {
        val index = map(c)
        m = m.max(end - start)
        while (start <= index) {
          map -= s(start)
          start += 1
        }
      }
      map.put(c, end)
      end += 1
    }
    m.max(map.size)
  }
}
```
这里自己维护一个map,在用队列实现的时候,用的是set,思想是一样的
