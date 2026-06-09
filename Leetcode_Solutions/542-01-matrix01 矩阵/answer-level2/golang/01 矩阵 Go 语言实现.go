用链表来模拟队列，进而实现 BFS ， 这里在链表的节点除了坐标信息还加入了距离信息，遇到满足条件的位置信息直接返回距离。
```
func updateMatrix(matrix [][]int) [][]int {
    for i:=0; i<len(matrix); i++ {
        for j:=0; j<len(matrix[i]); j++ {
            if matrix[i][j] != 0 {
                matrix[i][j] = findShort(matrix, i, j)
            }
        }
    }
    return matrix
}

func findShort(matrix [][]int, i, j int) int {
    marks := make([][]bool, len(matrix))
    for i:=0; i<len(matrix); i++ {
        marks[i] = make([]bool, len(matrix[i]))
    }
    return bfs(matrix, i, j, 1, marks)
}

type Point struct {
    i int
    j int
    val int
    next *Point
}

func bfs(matrix [][]int, i,j,res int, marks [][]bool) int {
    head := &Point{i,j,res, nil}
    tail := head
    for head != nil {
        if check(matrix, head.i , head.j) {
            return head.val
        }
        marks[head.i][head.j] = true
        if head.i>0 && !marks[head.i-1][head.j] {
            tail.next = &Point{head.i-1, head.j, head.val+1, nil}
            tail = tail.next
        }
        if head.j>0 && !marks[head.i][head.j-1] {
            tail.next = &Point{head.i,head.j-1,head.val+1,nil}
            tail = tail.next
        }
        if head.i<len(matrix)-1 && !marks[head.i+1][head.j] {
            tail.next = &Point{head.i+1, head.j, head.val+1, nil}
            tail = tail.next
        }
        
        if head.j<len(matrix[head.i])-1 && !marks[head.i][head.j+1] {
            tail.next = &Point{head.i, head.j+1, head.val+1, nil}
            tail = tail.next
        }
        
        head = head.next
    }
    return res
}

func check(matrix [][]int, i,j int) bool {
    if i>0 && matrix[i-1][j]==0 || i<len(matrix)-1 && matrix[i+1][j]==0 || j>0 && matrix[i][j-1]==0 || j<len(matrix[i])-1 && matrix[i][j+1]==0 {
        return true
    }
    return false
}
```
