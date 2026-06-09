用go的Map保存值对应的下标，在保存之时顺路判断另一个值是否在字典中，如存在直接返回，不存在直接入字典，这是一种空间换时间的算法，废话少说直接撸代码：
```
func twoSum(nums []int, target int) []int {
    // 字典
    keyMap := make(map[int]int)
    for j, value := range nums {
        // 判断字典中是否存在符合数
        if i, flag := keyMap[target-value]; flag {
            return []int{i,j}
        }
        keyMap[value] = j
    }
    
    return []int{-1,-1}
}

```
