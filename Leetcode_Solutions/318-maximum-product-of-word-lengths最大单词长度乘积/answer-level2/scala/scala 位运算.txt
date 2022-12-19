```scala
object Solution {
  def maxProduct(words: Array[String]): Int = {
    var res = 0
    val arr = Array.fill(words.length)(0)
    words.indices.foreach(i => {
      words(i).foreach(j => arr(i) |= 1 << (j - 'a'))
      (0 until i).foreach(j => if ((arr(i) & arr(j)) == 0) res = res.max(words(i).length * words(j).length))
    })
    res
  }
}
```
