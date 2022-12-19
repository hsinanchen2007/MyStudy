### 解题思路

双指针法。先将两个数组排序，然后i指向g数组，j指向s数组，如果s[j] >= g[i],说明满足胃口，则res+1，i++，j++，否则只有j++。两个数组其中一个遍历完成即可返回结果res。

### 代码

```golang
func findContentChildren(g []int, s []int) int {
	sort.Ints(g)
	sort.Ints(s)
    var i,j,res int = 0,0,0
	for i < len(g) && j < len(s) {
		if s[j] >= g[i] {
			res++
			i++
		}
		j++
	}
	return res
}
```