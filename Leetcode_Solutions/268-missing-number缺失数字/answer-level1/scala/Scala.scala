### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def missingNumber(nums: Array[Int]): Int = {
    var i = 0
    val num=nums.sorted
    while (i<num.length) {
      if(num(i)!=i){
        return i
      }
      i+=1
    }
    i
    }
}
```