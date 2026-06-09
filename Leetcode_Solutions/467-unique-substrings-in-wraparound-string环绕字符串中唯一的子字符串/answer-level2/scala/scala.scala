```scala_1 []
object Solution {
    def findSubstringInWraproundString(p: String): Int = {
        val dp = Array.fill(p.length)(0)
        val fre = scala.collection.mutable.HashMap[Char, Int]()
        def cond(i:Int):Boolean = i > 0 &&((p(i) - p(i-1) + 25) % 26 == 0)
        for{i <- 0 until p.length}{
            dp(i) += 1
            if(cond(i)) dp(i) += dp(i-1)
            fre.put(p(i), dp(i) max fre.getOrElse(p(i), 0))
        }
        ('a' to 'z') filter fre.contains map fre sum
    }
}
```
```scala_2 []
object Solution {
    def findSubstringInWraproundString(p: String): Int = {
        val dp = Array.fill(p.length)(0)
        val fre = Array.fill(26)(0)
        def cond(i:Int):Boolean = i > 0 &&((p(i) - p(i-1) + 25) % 26 == 0)
        for{i <- 0 until p.length}{
            dp(i) += 1
            if(cond(i)) dp(i) += dp(i-1)
            fre(p(i) - 'a') = fre(p(i) - 'a') max dp(i)
        }
        fre.sum
    }
}
```

