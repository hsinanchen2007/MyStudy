```ruby
object Solution {
 def pathInZigZagTree(label: Int): List[Int] = {
    def pow2(x:Int):Int = Math.pow(2,x).toInt
    def g(x:Int, i:Int):Int =  i % 2 match {
        // use Math to solve
        // i-th layer: 2^(i-1), 2^i -1
        // first a0 = 2^i -1 , d = -1, a0+n*d = x => n = a0 - x 
        case 0 => (pow2(i)-1 - x) / 2 + pow2(i-2)
        // first a0 = 2^(i-1), d = 1, a0 + n = x => n = x - a0
        case 1 => pow2(i-1) - 1 - (x - pow2(i-1))/2
    }

    def log2(x:Int, acc:Int = 0):Int = x match {
      case 0 => acc
      case _ => log2(x / 2, acc + 1)
    }

    def f(x:Int, acc:List[Int]):List[Int] = x match {
      case 1 => 1::acc
      case _ => f(g(x, log2(x)),x::acc)
    }
    f(label,Nil)
  }
}
```
