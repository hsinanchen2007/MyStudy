### 解题思路
[79. 单词搜索](https://leetcode-cn.com/problems/word-search/solution/custerxue-xi-bi-ji-shu-zu-de-hui-su-by-custergo-2/)

### 代码

```golang
func movingCount(m int, n int, k int) int {
  visited := make([][]bool, m+1)
  for i := range visited {
    visited[i] = make([]bool, n+1)
  }
  return dfs(0,0,m,n,k,visited)
}

func dfs(i, j, m, n, k int, visited [][]bool) int {
  // 先检查i,j是否在合法范围内
  // 或者i,j这个位置已经访问过
  // 或者虽然没有访问过，但这个位置的数位之和大于k
  if i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || getSum(i,j) > k {
    return 0 // 说明不能移动到这个位置
  }
  // 如果不是上面的情况,说明可以移动到i,j这个位置
  visited[i][j] = true // 于是把位置i,j标识为已访问过
  sum := 1 // 可以移动的步数，每次只能移动一步
  sum += dfs(i-1, j, m, n, k, visited) // 看能不能向上移动一步
  sum += dfs(i+1, j, m, n, k, visited) // 看能不能向下移动一步
  sum += dfs(i, j-1, m, n, k, visited) // 看能不能向左移动一步
  sum += dfs(i, j+1, m, n, k, visited) // 看能不能向右移动一步
  // visited[i][j] = false // 退递归后需要把当前位置的访问标记设置为false
  return sum
}

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

```