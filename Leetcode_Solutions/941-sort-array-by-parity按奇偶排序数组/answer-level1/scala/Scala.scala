### 解题思路
用两个listbuffer动态增加偶数元素和奇数元素，
再将两个listbuffer合并转换成array

### 代码

```scala
import scala.collection.mutable.ListBuffer
object Solution {
    def sortArrayByParity(A: Array[Int]): Array[Int] = {
    val list = new ListBuffer[Int]
    val list2 = new ListBuffer[Int]
    for (i <- A.indices) {
      if (A(i) % 2 == 0) {
        list.append(A(i))
      }else{
        list2.append(A(i))
      }
    }
    val list3=list++=list2
    list3.toArray
    }
}
```