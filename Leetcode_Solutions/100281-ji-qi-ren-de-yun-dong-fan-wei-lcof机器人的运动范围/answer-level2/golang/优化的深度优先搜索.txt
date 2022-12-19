### 解题思路
* 优化的深度优先
  * 坐标的数位之和可以直接使用枚举法，通过坐标x是否是10的倍数快速求解
  * 这里深度优先和广度优先都可以，优化的点是只能向右和向下探索。

### 代码

```golang
func movingCount(m int, n int, k int) int {
  bitSum := make([]int,101)
	for i := 1; i < 101; i++ {
		if i%10 == 0 {
      bitSum[i] = bitSum[i/10]
		} else {
			bitSum[i] = bitSum[i-1] + 1
		}
	}

  visit := make([][]bool,m)
  for i:=0;i<m;i++{
    visit[i] = make([]bool,n)
  }

  res := dfs(0,0,m,n,k,bitSum,visit)
  return res
}

func dfs(x,y,m,n,k int, bitSum []int,visit [][]bool) int{
  if x >= m || y >= n || bitSum[x]+bitSum[y]>k{
    return 0
  }
  if visit[x][y]{
    return 0
  }
  visit[x][y] = true
  sum := 1
  sum += dfs(x+1,y,m,n,k,bitSum,visit)
  sum += dfs(x,y+1,m,n,k,bitSum,visit)
  return sum
}
```