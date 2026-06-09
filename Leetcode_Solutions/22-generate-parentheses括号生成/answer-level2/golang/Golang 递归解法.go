```go
func generateParenthesis(n int) []string {
    var res []string
    gen(&res, n, n, "")
    return res
}

func gen(res *[]string, left, right int, substr string) {
    if left == 0 && right == 0 {
        *res = append(*res, substr)
        return
    }
    if left > 0 {
        gen(res, left-1, right, substr+"(")
    }
    if right > left {
        gen(res, left, right-1, substr+")")
    }
}
```