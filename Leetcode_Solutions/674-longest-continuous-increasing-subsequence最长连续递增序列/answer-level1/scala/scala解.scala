思路定义一个二维列表，将每个符合条件的列表进去，最后一次for循环找出长度最大的子列表
```
import scala.collection.mutable.{ListBuffer, Map, Stack}
object Solution {
    def findLengthOfLCIS(nums: Array[Int]): Int = {
        var length = 0
        if (nums.length == 0) {

        } else {
            val list = ListBuffer[List[Int]]()
            val list1 = ListBuffer[Int]()
            var i = 1
            var num = nums(0)
            list1.append(num)
            while (i <= nums.length - 1) {
                if (nums(i) > num) list1.append(nums(i)) 
                else {
                    list.+=(list1.toList)
                    list1.clear()
                    list1.append(nums(i))
                }
                num = nums(i)
                i += 1
            }
            if (list1.size > 0) list.append(list1.toList)        
            for (list <- list) length = math.max(length, list.length)
        }
        length
    }
}
```
