### 解题思路
根据元素为 0~n-1,  设置 hash 函数, f(x) = x.
即每个元素, 如果是 n, 就应该在 nums[n] 处. 

遍历数组并把元素与对应位置的元素交换. 交换之前判断是否对应位置已经是相同元素了, 如果是, hash 冲突, 该元素重复.

### 代码

```golang
func findRepeatNumber(nums []int) int {
    // sort.Ints(nums)
    var tmpo = 0 
    for i, v := range nums {
        for i != nums[i] {
            if nums[v] == v {
                return v
            }
            tmpo = nums[v] 
            // fmt.Println(tmpo)
            nums[v] = v
            nums[i] = nums[v]
        }
    }
    return tmpo
}
```