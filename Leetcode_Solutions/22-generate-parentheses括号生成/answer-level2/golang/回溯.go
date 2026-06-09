### 解题思路
此处撰写解题思路

### 代码

```golang
func generateParenthesis(n int) []string {
    var track string
    result := make([]string,0)
    backtrack(n,0,0,track, &result)

    return result
}

func backtrack( count, left, right int, track string,result *[]string) {
    if right == count {
        *result = append(*result, track)
        return 
    }

    if left == right { // 加左括号
        trackcopy := make([]byte, len(track))
        copy(trackcopy, track)

        backtrack(count, left+1, right, string(trackcopy)+"(", result)
    } else if left > right {
        trackcopy := make([]byte, len(track))
        copy(trackcopy, track)
        if left == count { // 加右

            backtrack(count, left, right+1, string(trackcopy)+")", result)
        } else {
            // 都可以
            backtrack(count, left, right+1, string(trackcopy)+")", result)
            backtrack(count, left+1, right, string(trackcopy)+"(", result)
        }
    }
}
```