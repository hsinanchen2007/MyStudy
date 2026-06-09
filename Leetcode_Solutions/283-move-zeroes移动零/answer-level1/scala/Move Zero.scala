### 解题思路
1、明确题目：除0以外元素保留其顺序，也就是非零元素依次和第一个零元素交换即可
2、zerroIndex 和数组下标一起前进
3、下标对应元素不为0时交换zeroIndex和数组下标的值
4、当zeroIndex和数组下标同为零时,zeroIndex停止前进
5、当zeroIndex < 数组下标时，说明zeroIndex已经指向第一个0，在交换之后将数组下标对应的值=0

### 代码

```scala
object Solution {
    def moveZeroes(nums: Array[Int]): Unit = {
        var zeroIndex:Int = 0
        for(index <- 0 until nums.length){
        if(nums(index) !=0){
            nums(zeroIndex) = nums(index)
            if(index!=zeroIndex) {
                nums(index) =0
            }
            zeroIndex += 1
        }
        }
    }
}
```