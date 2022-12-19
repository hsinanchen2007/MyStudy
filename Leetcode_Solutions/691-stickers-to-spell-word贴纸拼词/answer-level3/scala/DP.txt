```ruby
import scala.collection.mutable
object Solution {
 def minStickers(stickers: Array[String], target: String): Int = {
    val dp = Array.fill(1 << target.length)(-1)
    dp(0) = 0

    val table = mutable.Map.empty[String, Array[Int]]
    stickers foreach {str => table(str) = chCount(str)}

    def update(state:Int, x:String):Int = {
      var now = state
      val A = Array.fill(26)(0)
      (0 until 26) foreach {i => A(i) = table(x)(i)}

      for{
        i <- target.indices
        pos = target.length - i -1
        if (state & (1 << i)) == 0
      }{
        if(A(target(pos) - 'a') > 0){
          A(target(pos) - 'a') -= 1
          now |= 1 << i
        }
      }
      now
    }

    for{state <- 0 until 1 << target.length}{
      if(dp(state) != -1){
        for{
            x <- stickers
            now = update(state, x)
            if dp(now) == -1 || dp(now) > dp(state) + 1
        }
          dp(now) = dp(state) + 1
      }
    }
    dp.last
  }

  def chCount(str:String):Array[Int] = {
    val res = Array.fill(26)(0)
    str foreach { ch => res(ch - 'a') += 1}
    res
  }

}
```
