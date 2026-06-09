### 解题思路
此处撰写解题思路

### 代码

```golang
func sortArray(nums []int) []int {
    if len(nums) < 2{
        return nums
    }
    mid := nums[0]
    A := []int{}
    B := []int{}
    for i:=1; i < len(nums);i++{
        if nums[i] < mid{
            A = append(A,nums[i])
        }else{
            B = append(B,nums[i])
        }
    }
    return append(append(sortArray(A),mid),sortArray(B)...)
}
```