枚举所有可能的排列，字典树去重
```
var cnt int
var st [10]int
var vis [10]int
var tot int
var answer = 0

///字典树部分
type Student struct {
	f int
	next [27]int
}
var stu [100000]Student

func insert(){
	root:=0
	for i:=0;i<tot;i++{
		if st[i]==0{
			continue
		}
		next := stu[root].next[st[i]];
		if(next==0){
			cnt++
			next = cnt
			stu[root].next[st[i]] = next

		}
		root = next
	}
	if stu[root].f != 1&&root!=0{
		stu[root].f = 1
		answer++
	}
}

//搜索
func dfs(tiles string,deep int) {
	if(deep == tot) {
		insert()
		return ;
	}

	for i:=0;i<len(tiles);i++{
		if(vis[i]==0){
			vis[i] = 1
			st[deep] = int(tiles[i])-65+1
			dfs(tiles,deep+1)
			vis[i] = 0
		}
	}
	st[deep] = 0
	dfs(tiles,deep+1);
}

//初始化
func numTilePossibilities(tiles string) int {
	for i:=0;i<100000;i++{
		stu[i].f = 0
		for j:=0;j<27;j++{
			stu[i].next[j] = 0
		}
	}
	tot = len(tiles) + 1
	cnt = 0
	answer = 0
	dfs(tiles,0)
	return answer;
}
```