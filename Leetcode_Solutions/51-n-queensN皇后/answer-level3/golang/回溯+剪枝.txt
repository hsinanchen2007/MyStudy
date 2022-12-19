这道题我的思路是回溯+剪枝。
皇后之间不能攻击，西洋的皇后太霸道，不仅纵横无忌，还能斜着打，所以这也给了我们剪枝的手段。我们选择逐行进行递归，在递归的同时，可以将已确定位置的皇后所能攻击到的地方标记起来。

判断依据：

横线上，只需要在确定一个位置后，直接进行下一行即可。
竖线上，将确定位置后所在列进行记忆化，之后的位置与出现过的所有列进行比对。
“撇”，经过的所有格子有一个共同点，那就是横坐标加上纵坐标的结果是相同的。
“捺”，横坐标减去纵坐标的值进行记忆化。

```go
func solveNQueens(n int) [][]string {
    if n == 1 {
        return [][]string{{"Q"}}
    }
    if n <= 3{
        return [][]string{}
    }
    var re [][]int
    
    //三个map，shus就是竖，扑面而来的爱国情怀。
    
    shus,pies,nas := make(map[int]bool,n),make(map[int]bool,n),make(map[int]bool,n)
    DFS := func(rows []int, n int){}
    DFS = func(rows []int, n int){
        row := len(rows)
        if  row == n {
            aaaa := make([]int, len(rows))
            copy(aaaa,rows)
            //re = append(re,append([]int{},rows...))
            re = append(re,aaaa)
            return
        }

        for col:= 0; col< n; col++ {      
            if !shus[col] && !pies[row+col-1] && !nas[row-col-1]{
                shus[col] = true
                pies[row+col-1] = true
                nas[row-col-1] = true
                DFS(append(rows,col),n)
                shus[col] = false
                pies[row+col-1] = false
                nas[row-col-1] = false
            }
        }
    }

    DFS([]int{},n)
    return bQ(re,n)
}

func bQ (re [][]int,n int) (result [][]string) {
    for _,v := range re {
        s := []string{}
        for _,vv := range v{
            str := ""
            for i:=0;i<n;i++ {
                if i == vv {
                    str += "Q"
                }else{
                    str += "."
                }
            }
            s = append(s,str)
        }
        result = append(result,s)
    }
    return
} 
```