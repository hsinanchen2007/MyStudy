### 解题思路
此处撰写解题思路

### 代码

```golang
func subsetsWithDup(nums []int) [][]int {
    sort.Ints(nums)
    result := make([][]int,0)
    backtrack(nums, nil, &result)

    return result

}

func backtrack(nums, track []int, result *[][]int) {
    
    *result = append(*result, track)
      
    for i :=0; i < len(nums);  i++{

        if i !=0 && nums[i] == nums[i-1] {
            continue
        }

        numscopy := append([]int{}, nums...)
        trackcopy := append([]int{}, track...)

        backtrack(numscopy[i+1:], append(trackcopy, nums[i]), result)   

    }
    
}
```