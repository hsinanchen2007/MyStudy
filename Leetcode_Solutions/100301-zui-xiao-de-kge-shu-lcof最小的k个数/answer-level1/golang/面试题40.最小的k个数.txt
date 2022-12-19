### 解题思路

升序排序后取前k个数即可。

### 代码

```golang
func getLeastNumbers(arr []int, k int) []int {
    sort.Ints(arr)
    return arr[:k]
}
```