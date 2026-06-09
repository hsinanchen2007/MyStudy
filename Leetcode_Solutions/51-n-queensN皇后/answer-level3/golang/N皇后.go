### 解题思路
cur_state 那里想了好久，记录一下

### 代码

```golang
//var res [][]int
func solveNQueens(n int) [][]string {
    if n < 0 {
        return nil
    }
    res := make([][]int,0)
    //存放列，撇，捺
    cols:=make(map[int]bool,n)
    pies:=make(map[int]bool,n)
    nas:=make(map[int]bool,n)
    _dfs(n,0,[]int{},cols,pies,nas,&res)
    return generateResult(res,n)
}

func _dfs(n int,row int,cur_state []int,cols map[int]bool,pies map[int]bool,nas map[int]bool,res *[][]int){
    //recursion terminator
    if row >= n{
        // res = append(res,cur_state)
        tmp:=make([]int,n)
        copy(tmp,cur_state)
        (*res)=append((*res),tmp)
        return
    }
    for col:=0;col<n;col++{
        if cols[col] || pies[row + col] || nas[row - col]{
            continue
        }

        // fmt.Println("append(cur_state,col)")
        // fmt.Println(append(cur_state,col))
        // *cur_state = append((*cur_state),col)
        cols[col] = true
        pies[row + col] = true
        nas [row - col] = true
        //这里用append(cur_state,col) 不然还是要还原curstate/
        _dfs(n,row + 1,append(cur_state,col),cols,pies,nas,res)

        cols[col] = false
        pies[row + col] = false
        nas [row - col] = false
    }
    
}

func generateResult(res [][]int, n int) (result [][]string) {
	for _, v := range res {
		var s []string
		for _, val := range v {
			str := ""
			for i := 0; i < n; i++ {
				if i == val {
					str += "Q"
				} else {
					str += "."
				}
			}
			s = append(s, str)
		}
		result = append(result, s)
	}
	return
}


```