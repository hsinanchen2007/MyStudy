### 解题思路
这么看数组有点别扭,所以我先把数据反转.
例如  输入：nums = [1,1,2,3] 经过反转为[3,2,1,1] ,表示3出现2次,1出现一次,以此类推.
我使用scala编程,ArrayBuffer存储解码后的数据,循环遍历反转后的数据,
当前索引为偶数(表示第1,3,5...(2n+1))位的数字),则把当前数字加入到ArrayBuffer中
当前索引为奇数的时候(表示第2,4,6...(2n))位的数字),则表示前一个数字重复的次数,使用List.fill(次数)(需要重复的元素)实现把该元素重复
返回计算结果

### 代码

```scala
import scala.collection.mutable.ArrayBuffer
object Solution {
    def decompressRLElist(nums: Array[Int]): Array[Int] = {
    val newNums:Array[Int] = nums.reverse
    var ab: ArrayBuffer[Int] = ArrayBuffer[Int]()
    for (i <- 0 until (newNums.length)) {
      if (i.%(2) == 0) {
        ab.append(newNums(i))
      } else {
        if ((newNums(i) - 1) > 0) {
          ab.appendAll(List.fill(newNums(i) - 1)(newNums(i - 1)))
        }
      }
    }
    ab.toArray.reverse
    }
}
```