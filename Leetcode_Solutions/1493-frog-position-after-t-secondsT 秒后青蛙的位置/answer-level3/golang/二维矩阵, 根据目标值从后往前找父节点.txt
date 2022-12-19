### 解题思路
1. 二维矩阵 记录图 
2. grid[i][0] 记录出度 ， 算概率 
3. 从后往前找 
4. 比较 所需的最小时长， 以及该目标节点是否为叶子节点(出度是否为0))

### 代码

```golang
func frogPosition(n int, edges [][]int, t int, target int) float64 {
    if len(edges) == 0 || len(edges[0]) == 0 { 
        if target == n {
            return float64(1)
        }
        return float64(0)
    }
    
    grid := make([][]int, n+1)
    for i := 0; i < n+1; i++ {
        grid[i] = make([]int, n+1)
    }
    
    for i:= range edges {
        x := edges[i][0]
        y := edges[i][1] 
        grid[x][y] = 1  
        grid[y][x] = 1 
        if x <y {
            grid[x][0]++  // 出度
        } else {
             grid[y][0]++  // 出度
        }
        
       
    } 
    
    
    fmt.Println(grid)
    var (
        result int 
        resultpro float64
    )
    helper(target, 0, 1, &result, &resultpro, grid) 
    
    if t < result {  // 最小时长 大于规定的
        return float64(0)
    } 
    
    // 不是叶子节点的话， 规定时长过大 
    
    if grid[target][0] > 0 &&  t > result {
        return float64(0)
    }
    
    return resultpro
    
}

// 连通性， 概率为0
func helper(target int,time int, pro float64, result *int, resultpro *float64, grid [][]int) {
    if target == 1 { 
        *resultpro = pro
        *result = time
        return 
    }
    
    
    for i:=1; i < len(grid); i++ {
        if grid[i][target] == 1 && i < target{ 
            pro *= 1/float64(grid[i][0]) 
            
            helper(i, time+1,pro, result, resultpro, grid)
        }
    }
    
    
}
```