正则表达式，前后空格  ` *`，正负号 `[+-]?`，数字部分 `(\d+|\d+\.\d+|\d+\.|\.\d+)`，科学计数部分 `(e[+-]?\d+)?`
主要注意数字部分的正则匹配，有四种可能性，例如 `2, 2.2, 2., .2`

```go
func isNumber(s string) bool {
    matched, _ := regexp.Match(`^ *[+-]?(\d+|\d+\.\d+|\d+\.|\.\d+)(e[+-]?\d+)? *$`, []byte(s))
	return matched
}
```