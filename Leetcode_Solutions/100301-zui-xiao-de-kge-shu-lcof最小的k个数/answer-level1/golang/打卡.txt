### 解题思路
此处撰写解题思路

### 代码

```golang
func getLeastNumbers(arr []int, k int) []int {
    sort.Ints(arr)
    return arr[0:k]
}
```