
1. 反向遍历：每个1后面有多少0。如果这个1不翻转，则会有对应数量的0被翻转。通过map[idx]记录0的个数
2. 正向遍历：当前需要翻转的数量 = 前面的1的个数（通过遍历累计）+后面0的个数（第一步记录在map中，通过idx获取）。和min比较，取最小值
```
func minFlipsMonoIncr(S string) int {
    numOne, numZero := 0, 0
    oneS := make([]int, len(S))
    for i := len(S) - 1; i >= 0; i-- {
        if S[i] == '0' {
            numZero++
        } else {
            oneS[i] = numZero    
        }
    }
    if numZero == len(S) || numZero == 0 {
        return 0
    }
    min := numZero
    if len(S) - numZero < min {
        min = len(S) - numZero
    }
    for i := 0 ; i < len(S); i++ {
        if S[i] == '0' {
            continue
        }
        t := numOne + oneS[i]
        if t < min {
            min = t
        }
        numOne++
    }
    return min
}
```