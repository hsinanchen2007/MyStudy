执行用时 :0 ms, 在所有Go提交中击败了100.00%的用户
内存消耗 :3.8 MB, 在所有Go提交中击败了10.92%的用户

之前也提交过一次GO解题[力扣](https://leetcode-cn.com/problems/roman-to-integer/solution/go-jie-ti-12ms-ji-bai-100-by-54853315-cavvdnteyq/)，不知道编辑和删除，只好重新发布一份。
起因是有位热心的网友提醒我有个bug，因为__测试样例不严谨__，导致提交成功了。
所以新增了`showCount`变量来记录重复出现的字符，以免判断`IVIVIVIVIV`的时候错误计算。


```go
package main

import (
	"fmt"
	"strings"
)

func main(){
	fmt.Println(romanToInt("IVIVIVIVIV"))
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
			showCount := strings.Count(s,index)
			for i:=0;i<showCount;i++{
				num = append(num,val)
			}
			s = strings.Replace(s,index,"",showCount)
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