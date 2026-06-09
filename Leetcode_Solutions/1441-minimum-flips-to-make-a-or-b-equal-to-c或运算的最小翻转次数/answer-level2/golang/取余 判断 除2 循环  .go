### 解题思路
此处撰写解题思路

### 代码

```golang
func minFlips(a int, b int, c int) int {
    sum := 0
    for a >0 || b > 0 || c > 0 {
        a1 := a % 2
        b1 := b % 2
        c1 := c % 2 
        if a1 | b1 != c1 {
            if c1 == 1 {
                sum++
            }else {
                if a1 == 1 {
                    sum++
                }
                if b1 == 1 {
                    sum++
                }
            }
        }
        a = a / 2 
        b = b / 2 
        c = c /2
    } 
    return sum
}

// 最长的哪位
// 0 1  1
// 1 0  1
// 0 0  0
```