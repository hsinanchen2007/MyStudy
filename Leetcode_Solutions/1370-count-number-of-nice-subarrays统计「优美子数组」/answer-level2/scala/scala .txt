```scala []
object Solution {
    def numberOfSubarrays(A: Array[Int], k: Int): Int = {
        def f(l:List[Int], acc:List[Int] = Nil, count:Int = 0):List[Int] = l match {
            case Nil => count::acc
            case h::t => h % 2 match {
                case 0 => f(t, acc, count+1)
                case 1 => f(t, count::acc, 0)
            }
        }
        def g(A:Array[Int], k:Int)(i:Int, acc:Int):Int = 
        if(i+k >= A.length) acc else {
            g(A,k)(i+1, acc + (A(i+k)+1) * (A(i)+1))
        }
        g(f(A.toList).toArray, k)(0,0)        
    }
}
```