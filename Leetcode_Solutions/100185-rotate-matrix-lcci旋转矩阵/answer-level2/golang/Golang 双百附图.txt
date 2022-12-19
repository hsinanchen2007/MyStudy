1.先推导出 下一个位置和当前坐标的转变公式
matrix[i][j] -> matrix[j][n-i-1]
(i,j) 位置的值将会被赋给(j, n-1-1)位置
2.再想一下怎么遍历i, j 如图，应该遍历途中橙色区域的转移（这里没想出来怎么用一个循环条件，写了两个循环）
![image.png](https://pic.leetcode-cn.com/ad05194ad3835ccf467267c82e4d9af016250139ca1ba138abd14a1da9a09cfc-image.png)

```
func rotate(matrix [][]int)  {
    n := len(matrix)
    for i := 0;i < (n + 1)/2;i++{
        for j := 0;j < i;j++{
            tranverse(matrix, i, j, n)
        }
    }

    for i := (n + 1)/2;i < n ;i++{
        for j := 0;j < n - i ;j++{
            tranverse(matrix, i, j, n)
        }
    }
}

func tranverse(matrix [][]int, i, j, n int){
    //matrix[i][j] -> matrix[j][n-i-1]
    t0 := matrix[i][j]
    t1 := matrix[j][n-i-1]
    t2 := matrix[n-i-1][n-j-1]
    t3 := matrix[n-j-1][i]
    matrix[j][n-i-1] = t0
    matrix[n-i-1][n-j-1] = t1
    matrix[n-j-1][i] = t2
    matrix[i][j] = t3
}

```
![image.png](https://pic.leetcode-cn.com/d294e4f4125409ec43b3477b868ba807ceb9a8c03cc3bea62e90b053b1010b78-image.png)
