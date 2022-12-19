### 解题思路
此处撰写解题思路

### 代码

```golang
func subsets(nums []int) [][]int {
    result := make([][]int,0)
    backtrack(nums,nil, &result)

    return result
}

func backtrack(nums, track []int, result *[][]int) {
    
    *result = append(*result, track)
      
    

    for i :=0; i < len(nums);  i++{
        numscopy := append([]int{}, nums...)
        trackcopy := append([]int{}, track...)

        backtrack(numscopy[i+1:], append(trackcopy, nums[i]), result) 

    }

}
```