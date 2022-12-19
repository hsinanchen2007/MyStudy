### 解题思路
暴力解法，直接遍历两次
第一次遍历找到要匹配的第n个数字i，拿第一次遍历的数字与目标值进行减法操作得到结果x
第二次遍历找到第n个元素后的结果x并输出下标m
输出结果 n,m

### 代码

```golang
func twoSum(nums []int, target int) []int {
    result := make([]int ,2)
    for index,num:=range nums {
        if is,returnIndex:=findItemWhithNumber(nums,index, target-num);is{
            result[0] = index
            result[1]= returnIndex
            return result
        }
    }
    return result
}
func findItemWhithNumber(nums []int, beforeIndex, number int) (bool,int){
    for i:=beforeIndex+1;i<len(nums);i++ {
        if nums[i] == number{
            return true,i
        }
    }
    return false,-1
}
```