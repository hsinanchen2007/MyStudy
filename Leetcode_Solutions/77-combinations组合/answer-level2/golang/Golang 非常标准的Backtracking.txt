### 解题思路

### 代码

```golang
func combine(n int, k int) [][]int {
    var result [][]int 
    if k == 0{
        return result
    }
    var nums = make([]int, n)
    for i := range nums {
        nums[i] = i + 1
    }
    helper(&result, nums, 0, k)
    return result
}

func helper(result *[][]int, nums []int, index, k int) {
    //达到目的，进行回溯
    if index == k {
        *result = append(*result, append([]int{}, nums[0:k]...))
        return
    }
    for start := index; start < len(nums); start ++ {
        //可以在这里进行剪枝。去除递减的序列，防止结果重复
        if index == 0 || nums[start] > nums[index -1] {
            nums[start], nums[index] = nums[index], nums[start]
            helper(result, nums, index + 1, k)
            nums[index], nums[start] = nums[start], nums[index]
        }   
    }
    return 

}
```