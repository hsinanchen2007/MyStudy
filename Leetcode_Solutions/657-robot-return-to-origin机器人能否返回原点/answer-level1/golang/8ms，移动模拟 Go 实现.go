
![image.png](https://pic.leetcode-cn.com/397a3c25f95491f4e8967049225a92fec9ae9fd9b2d46ff2b8e54299af41523f-image.png)

```
func judgeCircle(moves string) bool {
    dx := []int{0,1,0,-1}
    dy := []int{1,0,-1,0}
    ops := map[rune]int{'R':0,'D':1,'L':2,'U':3}
    x,y := 0,0
    for _,move := range moves {
        x += dx[ops[move]]
        y += dy[ops[move]]
    }
    if x==0 && y==0 {
        return true
    }
    return false
}
```