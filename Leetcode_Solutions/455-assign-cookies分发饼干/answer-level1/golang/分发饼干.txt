### 解题思路
此处撰写解题思路
拿饼干去遍历孩子的胃口

### 代码

```golang
func findContentChildren(g []int, s []int) int {
	sort.Ints(g)//胃口
	sort.Ints(s)//饼干
	count:=0

	for i,j:=0,0;j< len(s)&&i< len(g);{
		if s[j]>=g[i]{
			count++
			i++
		}
		j++

	}
	return count
}
```