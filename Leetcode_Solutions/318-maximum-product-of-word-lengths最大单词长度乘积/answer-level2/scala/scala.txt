```
object Solution {
    def maxProduct(A: Array[String]): Int = {
        def f(A:Array[Boolean], B:Array[Boolean]):Boolean = {
            (A zip B) forall {case (x, y) => !(x && y)}
        }
        
        def g(fre:Array[Array[Boolean]])(A:Array[String]):Int = 
        ((for {
            i <- A.indices
            j <- i + 1 until A.length
            if f(fre(i), fre(j))
        } yield A(i).length * A(j).length) :+ 0 ).max
        
        def toVec(str:String):Array[Boolean] = {
            val arr = Array.fill(26)(false)
            str foreach {ch => arr(ch - 'a') |= true}
            arr
        }
        g(A map toVec)(A)
    }
}
```
