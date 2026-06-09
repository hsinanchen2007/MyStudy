### 解题思路
先设置一个基础值，然后转换为2Sum.
要注意去重：
1. 先排序
2. 基础值如果与前面的相同则跳过
3. 2Sum的去重主要是0022这种

### 代码

```golang
func threeSum(nums []int) [][]int {
	if len(nums) < 3 {
        return [][]int{}
    }
    var (
        result = [][]int{}
        helper func(start,end,target int)
    )
    sort.Ints(nums)
    helper = func(start,end,target int) {
        var (
            left = start
            right = end
        )
        for left < right {
            if left-1 >= start&&right+1 <=end && nums[left-1] == nums[left] && nums[right]==nums[right+1] {
                left ++
                right --
                continue
            }
            temp := nums[left]+nums[right]
            if temp == target {
                result = append(result,[]int{-target,nums[left],nums[right]})
                left ++
                right --
            }
            if temp < target {
                left++
            }
            if temp > target {
                right --
            }
        }
    }
    for i := 0; i < len(nums)-2; i ++ {
        if i-1 >= 0 && nums[i-1] == nums[i] {
            continue
        }
        helper(i+1,len(nums)-1,-nums[i])
    }
    return result
}
```