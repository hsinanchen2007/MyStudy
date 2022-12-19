```
package main

import (
	"fmt"
	"math"
	"strings"
	"unicode"
)

// 自动机什么的是学不会的，但各种情况的逻辑判断需要好好锻炼
func myAtoi(str string) int {
	flag := 1
	// 按找空白符分割字符串成一个切片
	strSlice := strings.FieldsFunc(str, unicode.IsSpace)
	//fmt.Println(strSlice, reflect.TypeOf(strSlice))
	// 分割后只需要判断切片内第一个元素即可
	var temp string
	// 防止输入""
	if len(strSlice) == 0 {
		return 0
	}
	if !unicode.IsDigit(rune(strSlice[0][0])) {
		if strSlice[0][0] == '+' {
			flag = 1
			strSlice[0] = strSlice[0][1:]
			//fmt.Println(strSlice[0])
		} else if strSlice[0][0] == '-' {
			flag = -1
			strSlice[0] = strSlice[0][1:]
		} else {
			return 0
		}
	}
	first := strSlice[0]
	for i := 0; i < len(first); i++ {
		if !unicode.IsDigit(rune(first[i])) {
			break
		} else {
			temp += string(first[i])
		}
	}
	// strToNum
	ans := 0
	for i := 0; i < len(temp); i++ {
		ans = int(temp[i]-'0') + ans*10
		if ans*flag > math.MaxInt32 {
			return math.MaxInt32
		}
		if ans*flag < math.MinInt32 {
			return math.MinInt32
		}
	}
	return flag * ans
}

func main() {
	//str := "-996 9k3 and 987"
	//str2 := "words and 987"
	str3 := "-91283472332"
	fmt.Println(myAtoi(str3))
}

```
