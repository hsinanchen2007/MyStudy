### 解题思路
 奇怪的知识增加了

见最高题解即可.

### 代码

```golang
func cuttingRope(n int) int {
    if n <= 3 {
        return n - 1
    }
    
    switch n%3 {
        case 0: return int(math.Pow(3, float64(n/3)))
        case 1: return int( math.Pow(3, float64(n/3 -1)) * 4)
        case 2: return int( math.Pow(3,float64(n/3)) * 2)
    }
    return -1
}
```