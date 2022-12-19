**定义**
n:第n行
m:第m列
f(n,m):到第n行、第m列最小路径和
x:三角型数组
**状态转移方程**
f(0,0) = x[0][0]
f(n,m) = min(f(n-1, m), f(n-1, m-1)) n>0,m>=0
**代码**
```
func minimumTotal(triangle [][]int) int {
    if len(triangle) == 0 {
        return 0
    }
    if len(triangle) == 1{
        return triangle[0][0]
    }
    
    t := make([][]int, len(triangle))
    t[0] = make([]int, 1)
    t[0][0] = triangle[0][0]
    
    
    for i := 1; i < len(triangle); i++ {
        
        t[i] = make([]int, len(triangle[i]))
        
        for j := 0; j < len(triangle[i]); j++ {
            
            var min int = math.MaxInt32
            if j-1 >= 0  && (min > t[i-1][j-1]) {
                min = t[i-1][j-1]
            }
            //if j+1 < len(triangle[i-1]) && (min>t[i-1][j+1]) {
              //  min = t[i-1][j+1]
            //}
            
            if j < len(triangle[i-1]) && (min > t[i-1][j]) {
                min = t[i-1][j]
            }
            
            t[i][j] = min+triangle[i][j] 
        }
    }
    //fmt.Println(t)
    var small int = t[len(triangle)-1][0]
    for i := 0; i < len(triangle); i++ {
        if t[len(triangle)-1][i]  < small {
            small = t[len(triangle)-1][i]
        }
    }
    
    return small
}
```
