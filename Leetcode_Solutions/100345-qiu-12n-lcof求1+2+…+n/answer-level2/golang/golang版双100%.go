### 解题思路
没有if，那就用&&来代替，不用循环那就找递归，最终代码如下

### 代码

```golang
func sumNums(n int) int {
    var f func(ret *int, n int) bool
	f = func(ret *int, n int) bool {
		*ret += n

		return n != 0 && f(ret, n-1)
	}

	var ans int
	f(&ans, n)

	return ans
}
```