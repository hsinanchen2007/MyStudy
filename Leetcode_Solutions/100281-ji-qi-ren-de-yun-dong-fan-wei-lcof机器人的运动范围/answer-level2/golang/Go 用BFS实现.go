### 解题思路
用切片做队列+BFS，0ms.欢迎提出改进意见

### 代码

```golang
func movingCount(m int, n int, k int) int {

    queue := make([]interface{},0)

    dx := [2]int{1,0}
    dy := [2]int{0,1}
    pair := [2]int {0,0}
    Push(&queue,pair)
    visited := make([][]bool,0)
    
    for i := 0; i < m; i++{
        var temp []bool
        for j := 0; j<n; j++ {
            temp = append(temp,false)
            
            
        }
        visited = append(visited,temp)
    }
    visited[0][0] = true
    
    ans := 0
    for len(queue) != 0 {
        for i := 0; i < len(queue); i ++ {
            node := Poll(&queue)
            row := node[0]
            col := node[1]
            ans++

            for j := 0; j < 2; j++ {
                nextRow := row + dx[j]
                nextCol := col + dy[j]
                if nextRow >= m || nextCol >= n || visited[nextRow][nextCol] || !isValid(nextRow, nextCol, k) {
                    continue
                }
                
                visited[nextRow][nextCol] = true
                pair := [2]int{nextRow,nextCol}
                Push(&queue,pair)
            }
        }
    }
    return ans
}
func getNumSum(num int) int{
    sum := 0
    for num > 0 {
        sum += num % 10
        num /= 10
    }
    return sum
}

func isValid (row,col,k int) bool{
    return getNumSum(row) + getNumSum(col) <= k
}

func Poll(queue *[]interface{}) [2]int {
    res := (*queue)[0].([2]int)
    *queue = (*queue)[1:]
    return res
}
func Push(queue *[]interface{},x interface{}) {
    *queue = append(*queue,x.([2]int))
}


```