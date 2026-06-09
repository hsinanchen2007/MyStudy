## 思路
```
一个N层三角，每层的值为f(n)(i) = f(n-1)(i-1)+f(n-1)(i),对于两条斜边f(n)(0)\f(n)(n-1) = 1 
```

```
// 迭代实现
func generate(rowsNum int) [][]int {
    // 构建容器
    res := make([][]int,rowsNum)
    for i:=0;i<rowsNum;i++ {
        temp := make([]int,i+1) // 为每行构建容器
        for j:=1;j<i;j++ {
            temp[j] = res[i-1][j-1] + res[i-1][j]
        }
        temp[0],temp[i] = 1,1
        res[i] = temp
    }
    return res
}


// 蛇皮递归实现
func generate(rowsNum int) [][]int {
    var p  [][]int
    return pascal(rowsNum,p)
}

func pascal(rows int, p [][]int) [][]int {
    if rows == 0 {
        return nil
    }
    if rows == 1 {
        p = append(p,[]int{1})
        return p
    }
    p = pascal(rows-1,p)
    temp := make([]int,rows)
    for i:=1;i<rows-1;i++ {
        temp[i] = p[rows-2][i-1]+p[rows-2][i]
    }
    temp[0],temp[rows-1] = 1, 1
    p = append(p,temp)
    return p
}


```

