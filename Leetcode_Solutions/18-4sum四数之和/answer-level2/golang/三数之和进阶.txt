### 解题思路
此处撰写解题思路
执行结果：通过
执行用时 :16 ms, 在所有 Go 提交中击败了44.42% 的用户
内存消耗 :2.7 MB, 在所有 Go 提交中击败了100.00%的用户
直接暴力解法，加一个循环即可
### 代码

```golang
func fourSum(nums []int, target int) [][]int {
    if nums == nil || len(nums) < 4 {
        return nil
    }
    sort.Ints(nums)
    len := len(nums)
    result := [][]int{}
    for i := 0 ; i < len - 3 ; i++{
        if i > 0 && nums[i] == nums[i-1]{
            continue
        }
       for j := i + 1 ; j < len - 2 ; j++{
           if j > i + 1 && nums[j] == nums[j-1]{
               continue
           }
           k , l := j + 1 , len - 1
           for k < l {
               if k > j + 1 && nums[k] == nums[k-1]{
                   k++ ; continue
               }
               if l < len - 2 && nums[l] == nums[l+1]{
                   l-- ; continue
               }
               sum := nums[i]+nums[j]+nums[k]+nums[l]
               if sum < target{
                   k++
               }else if sum > target{
                   l--
               }else{
                   result = append(result,[]int{nums[i],nums[j],nums[k],nums[l]})
                   k++ ; l--
               }
           }
       }
    }
    return result
}
```