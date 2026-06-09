每次循环后比较原始位置和当前位置的偏移和方向
如果位置相同，返回 true
如果位置不同，方向相同 ，返回 false

核心代码
```
 if now == left && start != [2]int{0, 0} {
    return false
 }
 if start == [2]int{0, 0} {
    return true
 }
```
整体代码
```
func isRobotBounded(instructions string) bool {
    visited := make(map[[2]int][2]int)
    start := [2]int{0, 0}
    left, right, up, down := [2]int{0, 1}, [2]int{0, -1}, [2]int{1, 0}, [2]int{-1, 0}
    now := left
    visited[start] = left
    for {
        for i := 0; i < len(instructions); i++ {
            if instructions[i] == 'G' {
                start[0] += now[0]
                start[1] += now[1]
            } else if instructions[i] == 'L' {
                if now == left {
                    now = up
                } else if now == up {
                    now = right
                } else if now == right {
                    now = down
                } else {
                    now = left
                }
            } else {
                if now == left {
                    now = down
                } else if now == down {
                    now = right
                } else if now == right {
                    now = up
                } else {
                    now = left
                }
            }
        }
        if now == left && start != [2]int{0, 0} {
            return false
        }
        if start == [2]int{0, 0} {
            return true
        }
    }
    return true
}
```