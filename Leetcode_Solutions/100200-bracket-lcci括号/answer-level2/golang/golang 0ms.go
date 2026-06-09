### 解题思路
bfs && 全局缓存

### 代码

```golang
var ret []string
func generateParenthesis(n int) []string {
    if n == 0 {return []string{}}
    if n== 1 {return []string{"()"}}
    ret = []string{}
    bfs(n, n, "")
    return ret
}

func bfs(left int, right int, str string){
	if right < left || left < 0{
		return
	}
    if left==0 && right == 0 {
        ret = append(ret, str)

    }

	if left > 0 {
        bfs(left -1, right, str + "(")
	}

	if right > 0 {
        bfs(left, right-1, str + ")")
	}
}

```