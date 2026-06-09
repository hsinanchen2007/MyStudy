

```golang
func searchMatrix(matrix [][]int, target int) bool {
    if matrix == nil || len(matrix) ==0 ||  len(matrix[0])==0 ||
		matrix[0][0] > target || matrix[len(matrix)-1][len(matrix[0])-1] < target {
		return false
        }
    i,j := 0,len(matrix[0])-1
    for i<=len(matrix)-1&&j>=0{
        if matrix[i][j]>target{
            j--
        }else if matrix[i][j]<target{
            i++
        }else{
            return true
        }
    }
    return false
}


```