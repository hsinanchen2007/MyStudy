### 解题思路
此处撰写解题思路

### 代码

```golang
func findJudge(N int, trust [][]int) int {
    //被相信，入度增加
	in:=make([]int,N)
    //相信别人，出度增加
	out:=make([]int,N)
	for _,v:=range trust{
		in[v[1]-1]++
		out[v[0]-1]++
	}
	for i:=0;i<N;i++{
		if in[i]==N-1&&out[i]==0{
			return i+1
		}
	}
	return -1
}
```