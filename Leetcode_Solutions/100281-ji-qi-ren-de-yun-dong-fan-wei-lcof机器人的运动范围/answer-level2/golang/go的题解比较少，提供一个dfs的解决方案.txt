看了已有的题解，都是用闭包形式去访问外部的变量（类似于全局变量）比如下面这种形式:

```golang
func movingCount(m int, n int, k int) int {
    ...
    
    check :=[100][100]bool{}

    ...    

    dfs := func(r,c,num int){
        ...

        check[r][c]=true
         
        ...
     }
    
    ...
}
```

个人不太喜欢这种写法，下面写一个常规版的go的dfs答案。

思路很简单:
1. 访问过的点不可达，返回0
2. 越界的点不可达，返回0
3. 数位和大于k的点不可达，返回0
4. 其余可达的点返回1，最后累加起来

有一个坑点，go初始化二维切片很蛋疼:
```golang
vis := make([][]bool, m + 1)
for i := 0; i < len(vis); i++ {
    vis[i] = make([]bool, n + 1)
}
```

正经答案:

```golang
func getSum(m, n int) int {
    sum := 0
    for m != 0 {
        sum += m % 10
        m = m / 10
    }
    for n != 0 {
        sum += n % 10
        n = n / 10
    }
    return sum
}

func dfs(x, y, m, n, k int, vis [][]bool) int {
    if getSum(x, y) > k {
        return 0
    } 
    if x >= m || y >= n || x < 0 || y < 0 {
        return 0
    }
    if vis[x][y] {
        return 0
    }
    vis[x][y] = true
    sum := 1
    sum += dfs(x - 1, y, m, n, k, vis)
    sum += dfs(x + 1, y, m, n, k, vis)
    sum += dfs(x, y - 1, m, n, k, vis)
    sum += dfs(x, y + 1, m, n, k, vis)
    return sum
}

func movingCount(m int, n int, k int) int {
    vis := make([][]bool, m + 1)
    for i := 0; i < len(vis); i++ {
        vis[i] = make([]bool, n + 1)
    }
    return dfs(0, 0, m, n, k, vis)
}
```