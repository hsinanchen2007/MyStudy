### 解题思路
+ 执行用时 : 0 ms, 在所有 Go 提交中击败了100.00%的用户
+ 内存消耗 : 2.7 MB, 在所有 Go 提交中击败了100.00%的用户

这里result必须全局变量，而且必须在generateParenthesis函数中初始化，因为
**提交时测试是不会重启全局环境的**
**提交时测试是不会重启全局环境的**
**提交时测试是不会重启全局环境的**

还有golang在递归时，切片容器不好传参进入，虽然切片是引用类型的，但是在使用内置append函数时**可能**会发生地址变化

### 代码

```golang
var result []string

func generateParenthesis(n int) []string {
    result = []string{}
    backtrack("", 2*n, 0)
    return result
}

// @param {int} open 左括号的个数
func backtrack(current string, max int, open int) {
    if len(current) == max {
        // 如果已满
        result = append(result, current)
        return
    }
    close := len(current) - open

    if open < max / 2 {
        backtrack(current + "(", max, open+1)
    }

    if close < open {
        backtrack(current + ")", max, open)
    }

    return
}


/**

    递归生成所有满足条件的字符串


*/
```