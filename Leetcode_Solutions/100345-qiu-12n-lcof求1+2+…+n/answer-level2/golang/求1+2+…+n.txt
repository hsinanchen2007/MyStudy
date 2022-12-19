### 解题思路
递归累加即可。

### 代码

```golang
func sumNums(n int) int {
    if n == 1 {
        return n
    }
    return sumNums(n-1) + n
}
```