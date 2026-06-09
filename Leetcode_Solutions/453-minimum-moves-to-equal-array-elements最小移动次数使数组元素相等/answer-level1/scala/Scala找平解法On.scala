### 解题思路
用scala，因为最近在做大数据相关的项目；解题思路及代码如下

### 代码

```scala
object Solution {
    def minMoves(nums: Array[Int]): Int = {
        //换个思路，这个题目要求是“找平”，加法可以找平，减法也可以找平；
        //n - 1 个元素增加 1，为了找平，等价于1个元素减一；所以答案是所有元素和最小元素的差值之和。
        //step 1 找到最小值
        val min = nums.min
        //step 2 计算差值之和
        val diff = nums.map(_ - min)
        diff.sum        
    }
}
```