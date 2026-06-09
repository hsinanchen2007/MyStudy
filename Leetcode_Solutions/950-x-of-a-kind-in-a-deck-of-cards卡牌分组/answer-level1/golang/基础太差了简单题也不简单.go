### 解题思路
辗转相除法求最大公约数，还有 map 的用法，GET

### 代码

```golang
func hasGroupsSizeX(deck []int) bool {
	if len(deck)<2{
		return false     //在统计之前判断总个数是否满足
	}
	var gcd func(a int,b int)int
	gcd = func(a int,b int)int{     //求最大公约数
		for a%b!=0{
			a,b=b,a%b
		}
		return b
	}
	g:=0
	map1 := make(map[int]int)
	for i:=0;i<len(deck);i++{      //把 deck 中的数出现的次数存入 map，以出现的数作为 key ，出现次数为 value.
		map1[deck[i]]++
	}
	for _,value := range map1{    // 遍历 map
		if g==0{
			g = value      //对 g 赋值
		}
		g = gcd(g,value)    //找最大公约数，如果大于 1，返回 true
	}
	return g>1
}
```