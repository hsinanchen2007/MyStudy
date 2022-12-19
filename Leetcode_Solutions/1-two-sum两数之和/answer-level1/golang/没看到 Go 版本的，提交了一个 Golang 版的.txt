```go
func twoSum(nums []int, target int) []int {
    
    //方法一: 循环嵌套 时间复杂度O(n²) 空间复杂度0(1)
    // length := len(nums)
    // for i := 0; i < length; i++ {
    //     for j := i + 1; j < length; j++ {
    //         if nums[i] == nums[j] {
    //             continue
    //         }
    //         if nums[i] + nums[j] == target {
    //             return []int{i, j}
    //         }
    //     }
    // }
    // return []int{}
    
     //方法二: 使用了一个map，时间复杂度O(n) 空间复杂度0(n)
    length := len(nums)
    a := map[int]int{}
    for i := 0; i < length; i++ {
        if v, ok := a[target - nums[i]]; ok {
             return []int{v, i}
        }
        a[nums[i]] = i
    }
    return []int{}
}
```