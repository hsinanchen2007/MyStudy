### 解题思路
只要把奇数和偶数分开就行。假定把偶数放在前面，初始一个起始位置”c”，遍历数组“A”如果当前值为偶数即和“c”的值交换，并且“c"本身加一。

### 代码

```golang
func sortArrayByParity(A []int) []int {
	c := 0
	for i := range A {
		if A[i]%2 == 0 {
			A[c], A[i] = A[i], A[c]
			c++
		}
	}
	return A
}
```