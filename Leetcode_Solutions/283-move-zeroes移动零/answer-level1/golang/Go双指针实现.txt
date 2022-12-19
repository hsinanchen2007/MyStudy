```
func moveZeroes(nums []int)  {
    k := 0
    for j :=0;j<len(nums);j++{
        if nums[j]!=0{
            if j !=k{
               nums[k],nums[j] = nums[j],nums[k]
            k++  
            }else{
                k++
            }
        }
    }
}
```
