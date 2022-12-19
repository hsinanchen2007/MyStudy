### 解题思路
905号的姐妹题。生成两个变量，一个保存奇数的index名为”d”，一个保存偶数名为”c“。遇到偶数则将其分配到A[c]然后将c加2保持c为偶数，奇数以此类推。

### 代码

```golang
func sortArrayByParityII(A []int) []int {
    arr := make([]int, len(A))
    c := 0
	d := 1
	for _, v := range A {
		if v % 2 == 0 {
			arr[c] = v
			c = c + 2
		} else {
			arr[d] = v
			d = d + 2
		}
	}
	return arr
}
```