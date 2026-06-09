执行用时 : 12 ms, 在Roman to Integer的Go提交中击败了100.00% 的用户


内存消耗 : 3.7 MB, 在Roman to Integer的Go提交中击败了11.26% 的用户

我感觉还不是很优秀，一定还有更短的写法。

``` go
package main

import (
	"fmt"
	"strings"
)

func main(){
	fmt.Println(romanToInt("IV"))
}

func romanToInt(s string) int {
	map1 := map[string]int{
		"I":1,
		"V":5,
		"X":10,
		"L":50,
		"C":100,
		"D":500,
		"M":1000,
	}
	map2 := map[string]int{
		"IV":4,
            "IX":9,
            "XL":40,
            "XC":90,
            "CD":400,
            "CM":900,
	}

	var num []int
	var number int
	for index,val := range map2{
		if strings.Contains(s,index){
			num = append(num,val)
			s = strings.Replace(s,index,"",1)
		}
	}

	for _,val := range s{
		if map1[string(val)] != 0{
			num = append(num,map1[string(val)])
		}
	}
		

	for _,value := range num{
		number += value
	}
	return number
}
```