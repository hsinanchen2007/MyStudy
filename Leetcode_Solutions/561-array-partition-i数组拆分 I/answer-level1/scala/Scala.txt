### 解题思路
先将数组排序，然后将下标为偶数的相加

执行用时 :
544 ms, 在所有 Scala 提交中击败了100.00%的用户
内存消耗 :
53.7 MB, 在所有 Scala 提交中击败了100.00%的用户

### 代码

```scala
object Solution {
    def arrayPairSum(nums: Array[Int]): Int = {
      val num = nums.sorted
    var res = 0
    var i = 0
    while (i < num.length) {
      res += num(i)
      i += 2
    }
    res  
    }
}
```