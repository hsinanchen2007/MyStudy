### 解题思路
此处撰写解题思路

### 代码

```golang
func numTrees(n int) int {
    g := map[int]int{0:1,1:1}
    for i:=2;i<=n;i++{
        for j:=1;j<=i;j++{
            g[i] += g[j-1]*g[i-j]
        }
    }
    return g[n]
}
```