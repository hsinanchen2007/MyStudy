# 解法一：利用数组规律

**Go：从左下角开始找，利用递增关系，大于往右边找，小于往上找，超出返回false**

--执行用时：40ms--消耗内存：6.3MB

```go
func findNumberIn2DArray(matrix [][]int, target int) bool {
    //以左下角为原点
    i:=len(matrix)-1//获取右下角y坐标
    j:=0//获取右下角x坐标
    for i>-1{
        if j<len(matrix[i]){
            if target<matrix[i][j]{
                i--  //小于target,向上查找
            }else if target>matrix[i][j]{
                j++ //大于targat,向右查找
            }else if target==matrix[i][j]{
                return true
            }
        }else{
            return false//超出数组返回false
        }
    }
    return false//超出matrix返回false
}
```
# 解法二：利用sort包下的SeachInts方法

Go：因为数组已经是递增关系，利用sort包下的SeachInts方法，遍历数组切片，查找数组中是否含有target值，如果查找不到，返回值是target应该插入数组的位置（会保持数组的递增顺序），此时需要分情况：
情况1：返回值=len(a)，即插入后长度+1，说明target数组内不存在。
情况2：返回值<len(a)，此时不能认为target在数组内，因为返回的是“插入后保持递增顺序的位置“，所以必须将target与数组中该位置的值进行比较，相同才返回true。

--执行用时：32ms--消耗内存：6.3MB

```go
func findNumberIn2DArray(matrix [][]int, target int) bool {
    for _,nums:=range matrix{
        i:=sort.SearchInts(nums,target)
        if i<len(nums)&&target==nums[i]{
            return true
        }
    }
    return false
}
```

