```scala []
object Solution {
    case class Frac(x:Int, y:Int){
        def + (that:Frac):Frac = {
            val q = y * that.y
            val p = x * that.y + that.x * y
            val m = gcd(abs(p), abs(q))
            if(p == 0) Frac(0,1) else Frac(p/m, q / m)
        }
        def get():String = x.toString + "/" + y.toString
    }
    def abs(x:Int):Int = if(x < 0) -x else x 
    def gcd(a:Int, b:Int):Int = if(a % b == 0) b else gcd(b, a % b)
    def f(str:String):Frac = str.split('/').toList match {
        case p::q::Nil => Frac(p.toInt, q.toInt)
    }
    def fractionAddition(exp: String): String = 
    exp replaceAll("-", "+-") split('+') filterNot (_=="") map f reduce (_+_) get 
}
```

