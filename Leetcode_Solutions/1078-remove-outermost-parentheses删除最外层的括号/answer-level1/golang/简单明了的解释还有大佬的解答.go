### 解题思路
一开始是没有头绪的，翻了不少题解，弄明白了其实就是找()括号里面的东西，包了一层的里面算做原语。两层的不算。
### 代码

```golang
func removeOuterParentheses(S string) string {
    var stack []string
    result:=""
    for _,s:=range S{
        // fmt.Println("stack=",stack)
        if s=='('{
            if len(stack)>0{
                result=result+"("
            }
            stack=append(stack,"(")
        }
        if s==')'{
            if len(stack)>1{
                result=result+")"
            }
            stack=stack[:len(stack)-1]
        }
    }
    return result
}
```
上面用go实现的版本，用时和内存消耗着实太低。主要在于slice的位移操作，复杂度都达到0(n2)了。

看下别人大佬运行0ms的答案确实牛逼。
```go

func removeOuterParentheses(S string) string {
	level := 0
	var res []rune  //用rune,相当于char
	for _, v := range S {
		if v == 41 {   //')' 
			level--
		}
		if level >= 1 { //如果是大于1说明还有左括号没匹配，这些都是原语句字符
			res = append(res, v)
		}
		if v == 40 {    //'('
			level++
		}
	}
    return string(res)
}
```