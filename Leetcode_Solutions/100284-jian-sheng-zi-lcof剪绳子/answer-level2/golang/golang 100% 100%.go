### 解题思路
就是看有几个3 =。= 特殊考虑33331 这种情况就变成33322
  
![image.png](https://pic.leetcode-cn.com/f207ccfd0287a290e9ea2ecb413548a3a1181cf222afcf2ab57473a482d1b0ef-image.png)

### 代码

```golang
func cuttingRope(n int) int {
    // 11  3 3 3 2
    // 10  3 3 3 1  => 3 3 2 2
    // 9   3 3 3
    // 8   3 3 2
    // 7   3 3 1  => 3 2 2
    // 6   3 3
    // 5   3 2 
    // 4   3 1  => 2 2  
    
    // 特殊情况
    // 3   2 1
    // 2   1 1
    // 1   1

    if n <= 2 {
        return 1
    }
    if n == 3 {
        return 2
    }
    // 能分成几份3
    parts := n / 3
    another := n % 3
    var result float64

    switch another {
        case 2:
            result = math.Pow(3, float64(parts))
            result *= 2
        case 1:
            result = math.Pow(3, float64(parts-1))
            result *= 4
        default:
            result = math.Pow(3, float64(parts))
    }
    return int(result)

}
```