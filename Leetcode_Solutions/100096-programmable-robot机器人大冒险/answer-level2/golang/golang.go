这题主要需要什么时候可以停止。因为机器人走的方向要么 x + 1， 要么 y + 1
所以当 x0 > x || y0 > y 时，说明机器人永远也走不到要求的点了，可以返回了
```
func robot(command string, obstacles [][]int, x int, y int) bool {
    obm := make(map[[2]int]bool)
    for i := 0; i < len(obstacles); i++ {
        obm[[2]int{obstacles[i][0], obstacles[i][1]}] = true
    }
    x0, y0 := 0, 0
    if x == x0 && y == y0 {
        return true
    }
    for {
        for i := 0; i < len(command); i++ {
            if command[i] == 'U' {
                y0++
            } else {
                x0++
            }
            if x0 == x && y0 == y {
                return true
            }
            if obm[[2]int{x0, y0}] {
                return false
            }
            if x0 > x && y0 > y {
                return false
            }
        }
    }
    return false
}
```
