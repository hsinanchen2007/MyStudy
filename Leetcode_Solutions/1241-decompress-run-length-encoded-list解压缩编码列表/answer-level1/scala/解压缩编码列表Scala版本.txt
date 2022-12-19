### 代码

```scala
import scala.collection.mutable.ArrayBuffer
object Solution {
    def decompressRLElist(nums: Array[Int]): Array[Int] = {
        val res:ArrayBuffer[Int] = new ArrayBuffer[Int]()
        for(i <- Range(0,nums.length-1,2)){
            for(j <- 0 until nums(i)){
                res.append(nums(i+1))
            }
        }
        res.toArray
    }
}
```