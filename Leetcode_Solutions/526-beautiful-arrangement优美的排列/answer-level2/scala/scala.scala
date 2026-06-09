```scala
object Solution {
  def countArrangement(N: Int): Int = {
    val res = Array.fill(1 << N)(0)
    res(0) = 1
    (0 until (1 << N)).foreach(i => {
      var idx = 1
      (0 until N).foreach(j => if (((i >> j) & 1) > 0) idx += 1)
      (1 to N).foreach(k =>
        if (!(((i >> (k - 1)) & 1) > 0) && (k % idx == 0 || idx % k == 0))
          res(i | (1 << (k - 1))) += res(i)
      )
    })
    res((1 << N) - 1)
  }
}
```