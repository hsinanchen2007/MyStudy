```
import scala.util.control.Breaks._
object Solution {
    def twoSum(nums: Array[Int], target: Int): Array[Int] = {
        val res = new Array[Int](2)
        breakable {
            for(i <- 0 until nums.length) {
                for(j <- i+1 until nums.length) {
                    if(nums(i)+nums(j)==target) {
                        res(0) = i
                        res(1) = j
                        break
                    }
                }
            }
        }
        res
    }
}
```
