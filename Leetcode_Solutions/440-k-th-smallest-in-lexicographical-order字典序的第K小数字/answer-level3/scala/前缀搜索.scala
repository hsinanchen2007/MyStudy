```ruby
object Solution {
  def findKthNumber(n: Int, k: Int): Int = {
    def f(x:BigInt, y:BigInt, acc:BigInt):BigInt = {
      if(x <= BigInt(n)) f(10*x, 10*y, acc +((BigInt(n)+1) min y) - x)
      else acc
    }
    def solve(k:Int, acc:Int):Int = k match {
      case 0 => acc
      case _ => f(acc, acc+1, 0) match {
        case count if BigInt(k) >= count =>solve((k-count).toInt, acc + 1)
        case count if BigInt(k) < count => solve(k-1, acc * 10)
      }
    }
    solve(k-1, 1)
  }
}
```
