1.暴力求解
时间复杂度O(n),空间复杂度O(n)
```
func moveZeroes(nums []int)  {
    arr := make([]int, len(nums), len(nums))
    cnt := 0
    for i:=0; i<len(nums); i++ {
        if nums[i] != 0 {
            arr[cnt] = nums[i]
            cnt++
        }
    }

    for i := cnt; i < len(nums); i++ {
        arr[i] = 0
    }

    for i := 0; i < len(nums); i++ {
        nums[i] = arr[i]
    }    
}
```
2.快慢指针
时间复杂度O(n),空间复杂度O(1)
```
func moveZeroes(nums []int)  {
    for i,j:=0,0; i<len(nums); i++ {
        if nums[i] != 0 {
            nums[j], nums[i] = nums[i], nums[j]
            j++
        }
    }
}
```
