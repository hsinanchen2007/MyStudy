```scala []
object Solution {
    def checkValidString(s: String): Boolean = {
        def f(l:List[Char], i:Int, l1:List[Int], l2:List[Int]):Boolean = l match {
            case Nil => l1.length <= l2.length && (l1 zip l2).forall{case (x,y) => x < y}
            case '('::t => f(t, i+1, i::l1, l2)
            case ')'::t => (l1, l2) match {
                case (Nil, Nil) => false
                case (Nil, h::t2) => f(t, i+1, l1, t2)
                case (h::t1, _) => f(t, i+1, t1, l2)
            }
            case '*'::t => f(t, i+1, l1, i::l2)
        }
        
        f(s.toList, 0, Nil, Nil)
    }
}
```
