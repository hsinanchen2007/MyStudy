### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def twoSum(nums2: Array[Int], target: Int): Array[Int] = {

      val nums:Seq[(Int, Int)] = nums2.zipWithIndex.sortBy(_._1)

      var i = 0
      var j = nums.length - 1
      while (true){
        if(nums(i)._1 + nums(j)._1 > target && j > 0) {
          j -= 1
        }else if(nums(i)._1 + nums(j)._1 < target && i < nums.length){
          i += 1
        }else{
          return Array(nums(i)._2, nums(j)._2)
        }
      }
      Array()
    }
}
```