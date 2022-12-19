```
1. 暴力法 找到每一个组合的乘积
func maxProduct(nums []int) int {
    maxSum := nums[0]
    for i:=0; i< len(nums); i++ {
        sum :=1
        for j:=i; j <len(nums); j++ {
            sum *= nums[j]
            if sum > maxSum {
                maxSum = sum
            }
        }
    } 
    return maxSum
}
```
