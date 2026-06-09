### 解题思路
- 括号总是成对出现，即f(n)为n时的所有组合
- 那么在插入第n对括号时，看一下这一对括号插入的位置，即固定左括号n，查找右括号可能的位置
- 由于匹配的括号对，其内部必然所有括号都是匹配的，外部也是，所以有
- f(n) = U(f(k))f(n-1-k)
- 左括号n可以在任何位置，但是肯定都与左括号固定在最左边重复，因为无论怎么变化，最左边必然是个左括号
### 代码

```golang
func generateParenthesis(n int) []string {
    if n == 0{
        return nil
    }
    if n == 1{
        return []string{"()"}
    }
    var buffer [][]string = make([][]string, n+1)
    buffer[0] = nil
    buffer[1] = []string{"()"}
    for i:=2; i<=n; i++{
        for j:=0; j<i; j++{
            buffer[i] = append(buffer[i],span2(buffer[j], buffer[i-1-j])...)
        }
    }
    return buffer[n]
}
// (as)bs
func span2(as,bs []string)[]string{
    if len(as) == 0{
        as = []string{""}
    }
    if len(bs) == 0{
        bs = []string{""}
    }
    var results []string
    for _,a := range as{
        for _,b := range bs{
            results = append(results, "("+a+")"+b)
        }
    }
    return results
}
```