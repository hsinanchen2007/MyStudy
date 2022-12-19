### 解题思路
此处撰写解题思路

### 代码

```golang
func lastRemaining(n int, m int) int {
    var ans int 
    for i := 2; i <= n; i++ {
        ans = (ans+m)%i;
    } 
    return ans;
}
```