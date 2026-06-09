1. 暴力循环固定了j的位置,左边i遍历,右边k遍历, 在case115会超时
2. 因为i,j确定之后, 那么我们就知道了等分后数组的和是多少,这样就可以算出所需要的ak的值,所以我们提前扫一遍数组,记录没个数值的index.就可以了.
```python
object Solution {
    def splitArray(nums: Array[Int]): Boolean = {
        if(nums.length < 7) false else f(nums)
    }
    def f(A:Array[Int]):Boolean = {
        val cum = Array.fill(A.length)(0)
        cum(0) = A.head
        (1 until cum.length) foreach {i => cum(i) = A(i)+ cum(i-1)}
        val table = scala.collection.mutable.HashMap[Int,List[Int]]()
        A.zipWithIndex.foreach {case (x,i) => table.put(x, i::table.getOrElse(x, Nil))}
        def g(j:Int, i:Int):Boolean = {
            cum(j-1) - cum(i) == cum(i-1)
        }
        def g2(j:Int, i:Int, k:Int):Boolean = {
            cum(k-1) - cum(j) == cum(i-1) && 
            cum.last - cum(k) == cum(i-1)
        }
        
        // {} ai {} aj {} ak{}
        // s: sum(A) 
        // right = cum(j-1) - ai = (s - aj - ai - ak)/ 2
        // => ak = cum.last - aj - ai - 2(cum(j-1) - ai)
        
        for{
            j <- 3 until A.length - 3
            i <- 1 until j-1
            if g(j,i)
            //k <- j+2 until A.length
            ak =  cum.last - A(j) - A(i) - 2*(cum(j-1) - A(i))
            k <- table.getOrElse(ak, Nil).filter(x => x>= j + 2)
            if g2(j,i,k)
        } return true
        false
    }

}
```
