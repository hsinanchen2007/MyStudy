### 解题思路

太简单，两行搞定...

### 代码

```golang
func merge(A []int, m int, B []int, n int)  {
	A = append(A[:m],B...)
	sort.Ints(A)
}
```