```
func longestCommonSubsequence(str1 string, str2 string) int {
    if len(str1) == 0 || len(str2) == 0 {
        return 0
    }

    r := len(str1)
    c := len(str2)
    numArr := make([][]int, r+1)
    for i:=0; i<r+1; i++ {
        numArr[i] = make([]int, c+1)
    }
    for i:=1; i<r+1; i++ {
        for j:=1; j<c+1; j++ {
            if str1[i-1] == str2[j-1] {
                numArr[i][j] = numArr[i-1][j-1] + 1
            } else {
                numArr[i][j] = max(numArr[i][j-1], numArr[i-1][j])
            }
        }
    }
    return numArr[r][c]
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```
