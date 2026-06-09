### 解题思路

- `for`循环遍历排序数组`nums`  
- 使用`map`记录数组中不同数字的出现次数  
- 根据输入的`target`作为`map`的`key`，返回对应的结果

### 代码

```golang
func search(nums []int, target int) int {
    TargetCount := make(map[int]int)
    for _,num := range nums {
        TargetCount[num]++
    }

    return TargetCount[target]
}
```