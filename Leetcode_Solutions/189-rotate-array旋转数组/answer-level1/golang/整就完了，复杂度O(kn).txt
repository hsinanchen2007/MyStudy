### 解题思路
此处撰写解题思路
暴力点，主要是想明白
### 代码

```golang
func rotate(nums []int, k int)  {
    
    if k > len(nums) {
        k = k - len(nums)
    }

    //先写边界
    if k == 0 || len(nums) == 1 || k == len(nums){
        return
    }

    //count为要移动到最后位置的元素
    var count int
    count = len(nums) - k - 1
    var sum []int
    for j := len(nums)-k; j < len(nums); j++ {
        //把分隔点之后的数据按顺序存到新数组中
        sum = append(sum, nums[j])
    }

    //把分隔符之前的元素后移k个位置
    for i := len(nums)-1; i > 0; i-- {
        if count < 0 {
            break
        }
        nums[i] = nums[count]
        count--
    }
    //把之前存的元素赋值到数组前k位
    for i := 0; i < len(nums); i++ {
        if i == k {
            break
        }
        nums[i] = sum[i] 
    }
}
```