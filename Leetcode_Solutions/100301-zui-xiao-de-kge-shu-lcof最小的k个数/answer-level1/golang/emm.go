### 解题思路
emmm

### 代码

```golang
func getLeastNumbers(arr []int, k int) []int {
    sort.Ints(arr)
	return arr[:k]
}   
```