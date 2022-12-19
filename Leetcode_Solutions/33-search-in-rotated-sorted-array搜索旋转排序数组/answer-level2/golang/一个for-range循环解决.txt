### 解题思路

利用`for-range`遍历`nums`数组中的每一个元素，如果满足`target`，返回下标，否则等循环结束直接返回-1。

### 代码

```golang
func search(nums []int, target int) int {
    for index,num := range nums {
        if num == target {
            return index
        }
    }
    return -1
}
```