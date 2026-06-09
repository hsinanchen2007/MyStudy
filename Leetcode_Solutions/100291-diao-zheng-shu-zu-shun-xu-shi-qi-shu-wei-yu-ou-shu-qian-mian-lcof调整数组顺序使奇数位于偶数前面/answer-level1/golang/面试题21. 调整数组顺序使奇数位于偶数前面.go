### 解题思路
俩个思路：
1. 用俩个切片做记录
2. 用双指针，左边指向偶数， 右边指向奇数；交换俩个值

### 代码

```golang 第一个思路
func exchange(nums []int) []int {
    
    numjishu := []int{}
    numoushu := []int{}
    
    for i:=0; i<len(nums); i++ {
        if nums[i]%2 == 1 {
            numjishu = append(numjishu, nums[i])
        }else{
            numoushu = append(numoushu, nums[i])
        }
    }
    return append(numjishu, numoushu...)
}
```

```第二个思路
func exchange(nums []int) []int {
    
    if len(nums) <= 1 {
        return nums
    }
    l := 0
    r := len(nums)-1
    for l < len(nums) && nums[l] % 2 != 0 {
        l++
    }
    for r >=0  && nums[r] % 2 == 0{
        r--
    }
    for l < r {
        nums[l], nums[r] = nums[r], nums[l]
        for nums[l] % 2 != 0 {
        l++
        }
        for nums[r] % 2 == 0 {
        r--
        }
    }
    return nums
}
```
