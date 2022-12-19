### 解题思路
此处撰写解题思路
用Go库函数排序，然后返回前k个元素的切片。
### 代码

```golang
import "sort"
func getLeastNumbers(arr []int, k int) []int {
    sort.Ints(arr)
    return arr[ : k]
}
```