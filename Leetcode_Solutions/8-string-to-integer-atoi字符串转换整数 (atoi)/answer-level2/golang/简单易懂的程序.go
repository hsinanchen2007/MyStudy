package main

import (
	"fmt"
	"math"
	"strings"
)

func myAtoi(str string) int {
	ret, substr := getValidStr(str)
	if !ret {
		return 0
	}
	return convertNum(substr)
}

func getValidStr(str string) (bool, string) {
	str = strings.TrimSpace(str)

	if len(str) == 0 {
		return false, ""
	}

	if len(str) == 1 {
		if str[0] < '0' || str[0] > '9' {
			return false, ""
		}
	}

	if (str[0] < '0' || str[0] > '9') && str[0] != '-' && str[0] != '+' {
		return false, ""
	}

	index := 0
	for i := 0; i < len(str); i++ {
		index = i
		if str[0] == '-' || str[0] == '+' {
			continue
		}
		if str[0] < '0' || str[0] > '9' {
			break
		}
	}
	return true, str[:index+1]
}

func convertNum(str string) int {
	var base int = 1
	var val int = 0

	if str[0] == '-' {
		base = -1
	}
	startIndex := 0
	if str[0] == '-' || str[0] == '+' {
		startIndex = 1
	}

	for i := startIndex; i < len(str); i++ {
		if str[i] >= '0' && str[i] <= '9' {
			val = val*10 + int(str[i]-'0')
			if base == -1 {
				tmp := base * val
				if tmp < math.MinInt32 {
					val = math.MinInt32
					return val
				}
			}else if val > math.MaxInt32 {
				val = math.MaxInt32
				return val
			}
		} else {
			break
		}
	}

	return base*val
}

func main() {
	// str := "4193 with words"
	// str := "-91283472332"
	// str := "3.14159"
	str := "-42"
	_, ret := getValidStr(str)
	fmt.Println(ret)
	fmt.Print(convertNum(ret))
}
