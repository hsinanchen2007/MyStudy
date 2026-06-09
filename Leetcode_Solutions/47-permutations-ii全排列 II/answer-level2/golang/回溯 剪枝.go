### 解题思路
此处撰写解题思路

### 代码

```golang
func permuteUnique(nums []int) [][]int {
    result := make([][]int,0)
    sort.Ints(nums)
    backtrack(nums, nil, &result)

    return result
}


func backtrack(nums, track []int, result *[][]int) {
    if len(nums) == 0 {
        *result = append(*result, track)
        return 
    }


    for i :=0; i < len(nums); i++ {
        if i!=0 && nums[i] == nums[i-1] {
            continue
        } 
        numscopy := append([]int{}, nums...)
        trackcopy := append([]int{}, track...)
        backtrack(append(numscopy[:i],numscopy[i+1:]... ), append(trackcopy, nums[i]), result )

    }

}
```