方法1：反转3次
空间复杂度O(1)
```
func rotate(nums []int, k int)  {
    k = k%len(nums)
    reverse(nums[:len(nums)-k])
    reverse(nums[len(nums)-k:])
    reverse(nums[:])
}

func reverse(nums []int){
    i,j := 0,len(nums)-1
    for i<j{
        nums[i],nums[j] = nums[j],nums[i]
        i++
        j--
    }
}
```

利用切片，额外利用了空间，空间复杂度不是O(1)
```
func rotate(nums []int, k int)  {
    k = k%len(nums)
    res := append(nums[len(nums)-k:],nums[:len(nums)-k]...)
    nums = append(nums[:0],res...)
}
```

