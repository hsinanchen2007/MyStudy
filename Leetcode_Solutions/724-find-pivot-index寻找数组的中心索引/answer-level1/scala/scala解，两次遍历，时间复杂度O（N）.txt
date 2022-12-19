将问题转化为：中心索引左边数之和的两倍与数组所有元素总和相等
```
import scala.collection.mutable.{Map,ListBuffer}
import java.util.Arrays
object Solution {
    def pivotIndex(nums: Array[Int]): Int = {
        if (nums.length < 1) {
      return -1
    } else if (nums.length == 1) {
      return 0
    } else {
      val indexList: ListBuffer[Int] = ListBuffer[Int]()
      var sum = 0
      for (num: Int <- nums) {
        sum = sum + num
      }
      var temp = nums(0)
      if (sum - nums(0) == 0) {
        indexList.append(0)
      }
      for (i <- 1 until nums.length) {
        temp = temp + nums(i)
        if ((temp - nums(i)) * 2 + nums(i) == sum) {
          indexList.append(i)
        }
      }
      val result = indexList.toArray
      if (result.size > 0) {
        Arrays.sort(result)
        return result(0)
      } else {
        return -1
      }
    }
    -1
    }
}
```
