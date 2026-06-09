### 解题思路
目标是：竟可能少的使用循环。
所以，这里我们使用map存储目标差值
在每次循环前判断当前值是否存在于map差值中，如果存在直接返回
如果不存在继续循环并且当每次循环之后计算出当前值的差值并且存储到map中。

### 代码

```golang
func twoSum(nums []int, target int) []int {
    obj := make(map[int]int, len(nums))
    for key, val := range nums{
        result, ok := obj[val]
        if ok {
            return []int{result, key}
        }
        obj[target-val] = key
    }
    return []int{0, 0}
}
```