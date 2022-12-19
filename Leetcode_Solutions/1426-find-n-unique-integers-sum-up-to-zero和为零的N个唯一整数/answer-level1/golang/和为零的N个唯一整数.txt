### 解题思路
奇数先填加一个0，偶数不添加。然后依次填入1，-1,2,-2,3，-3...直到数组长度等于n

### 代码

```golang
func sumZero(n int) []int {
	var ret []int
	if n % 2 != 0 {
		ret = append(ret, 0)
	}
	v := 1
	for len(ret) < n {
		ret = append(ret, v)
		ret = append(ret, v * -1)
		v++
	}
	return ret
}
```