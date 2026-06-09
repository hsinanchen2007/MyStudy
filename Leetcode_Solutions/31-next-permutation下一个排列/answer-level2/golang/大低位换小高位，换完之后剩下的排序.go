### 解题思路
脑残办法，大低位换小高位，换完之后剩下的排序

### 代码

```golang
func nextPermutation(nums []int)  {
    if len(nums) <= 1 {
        return
    }
    for i:=len(nums)-2; i >= 0; i-- {
        for j:=len(nums)-1; j >= i; j-- {
            if i == 0 && j == 0 {
                sort.Ints(nums)
                return
            }
            if nums[j] > nums[i] {
                nums[j], nums[i] = nums[i], nums[j]
                sort.Ints(nums[i+1:])
                return
            }        
        }
    }   

}
```