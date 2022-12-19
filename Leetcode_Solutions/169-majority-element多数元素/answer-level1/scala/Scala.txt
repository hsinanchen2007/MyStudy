### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
        def majorityElement(nums: Array[Int]): Int = {
           val num = nums.sorted
    num(num.length / 2) 
        }
}
```