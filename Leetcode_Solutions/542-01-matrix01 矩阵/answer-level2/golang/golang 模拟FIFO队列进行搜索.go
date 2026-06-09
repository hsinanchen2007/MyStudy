```
func updateMatrix(matrix [][]int) [][]int {
    var maxN int = math.MaxInt32

    stack := make([]int, 0)

    dp := make([][]int, len(matrix))
    for k, v := range matrix {
        dp[k] = make([]int, len(v))
        for k2 := range dp[k] {
            if matrix[k][k2] == 0 {
                dp[k][k2] = 0
                stack = append(stack, []int{k, k2}...)
            } else {
                dp[k][k2] = maxN
            }
        }
    }
    
    for len(stack) > 0 {
        opX, opY := stack[0], stack[1]
        stack = stack[2:]
        
        left, right, top, bottom := maxN, maxN, maxN, maxN

        // 处理未被计算过的点
        if dp[opX][opY] == maxN {
            if opX-1 >= 0 {
                top = dp[opX-1][opY]
            }
            if opX+1 < len(matrix) {
                bottom = dp[opX+1][opY]
            }
            if opY-1 >=0 {
                left = dp[opX][opY-1]
            }
            if opY+1 < len(matrix[0]) {
                right = dp[opX][opY+1]
            }

            dp[opX][opY] = min(top, bottom, left, right) + 1
        }
        
        // append上下左右没有计算过的到stack
        if opX-1>=0 && dp[opX-1][opY] == maxN {
            stack = append(stack, []int{opX-1, opY}...)
        }
        if opX+1<len(matrix) && dp[opX+1][opY] == maxN {
            stack = append(stack, []int{opX+1, opY}...)
        }
        if opY-1>=0 && dp[opX][opY-1] == maxN {
            stack = append(stack, []int{opX, opY-1}...)
        }
        if opY+1<len(matrix[0]) && dp[opX][opY+1] == maxN {
            stack = append(stack, []int{opX, opY+1}...)
        }
    }

    return dp
}

func min(n1, n2, n3, n4 int) int {
    a, b := n1, n3
    if n1 > n2 {
        a = n2
    }
    if n3 > n4 {
        b = n4
    }
    if a > b {
        return b
    }
    return a
}
```
