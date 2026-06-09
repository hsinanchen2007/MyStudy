### 解题思路
统计每个单独数字的数量，然后求最大公约数，如果能被len(deck)整除就可以分组

### 代码

```golang
func hasGroupsSizeX(deck []int) bool {
 if len(deck)==1 {
     return false 
 }

m:=make(map[int]int)
for _,v:=range deck {
   m[v] = m[v]+1
}
g:=m[0] //最大公约数
for i:=1;i<len(deck);i++ {
   g=gcd(g,m[i])
}
if g==1 {
    return false
}
return len(deck) % g ==0
}

func gcd(a,b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a % b)
}
```