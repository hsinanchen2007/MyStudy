因为所有数字都在0 ~n-1之间；所以可以使用桶的思想。
用n-1个桶来装每个数字的次数。

```
代码块
func findRepeatNumber(nums []int) int {
    m := len(nums)
    a := make([]int,m) 
    re := 0 
    for i := 0;i<m;i++{
        a[nums[i]]++    
    }
    for i := 0;i<len(a);i++{
        if a[i]>=2{
            re = i
            break
        }
    }
    return re
}
```
