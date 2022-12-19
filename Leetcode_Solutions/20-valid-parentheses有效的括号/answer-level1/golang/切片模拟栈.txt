关于判断符号的那部分是之前偶然间看到的,再找原文就找不到了,用时0S内存2.1M
```
package main

import "fmt"

func PushSS(s *[]byte, v byte) {
	*s = append(*s, v) //追加到切片最后一位
}
func PopSS(s *[]byte) byte {
	if len(*s) == 0 {
		return 0
	}
	lens := len(*s)
	v := (*s)[lens-1]  //获取最后一位
	*s = (*s)[:lens-1] //删掉最后一位
	return v
}
func GetLast(s *[]byte) byte {
	lens := len(*s)
	if lens > 0 {
		return (*s)[lens-1] //返回栈顶指针的值
	}
	return 0
}
func Useful(str string) bool {
	line := []byte(str)
	stack := make([]byte, 0)
	//stack := new([]byte)
	for i := 0; i < len(line); i++ {
		if line[i]-GetLast(&stack) <= 2 && line[i]-GetLast(&stack) != 0 { //前半部分判断两个符号的ascII码挨着后半部分判断不是同一个符号
			PopSS(&stack)
		} else {
			PushSS(&stack, line[i])
		}
	}
	if len(stack) == 0 {
		return true
	}
	return false
}
func main() {
	li := "{}[()]"
	il := "{([])}"
	err := "{}{)"
	same := "[[[]]]"
	fmt.Println(Useful(li))
	fmt.Println(Useful(il))
	fmt.Println(Useful(err))
	fmt.Println(Useful(same))
}

```
