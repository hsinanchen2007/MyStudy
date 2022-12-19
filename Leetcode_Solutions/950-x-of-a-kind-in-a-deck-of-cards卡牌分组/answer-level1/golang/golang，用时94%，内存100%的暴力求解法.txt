### 解题思路
计算各数频次，然后取最小的次数，依次判断其约数是否是其他数的约数，如果存在这样的约数，则返回true

### 代码

```golang
func hasGroupsSizeX(deck []int) bool {
	mp:=make(map[int]int)
	groups:=0
	for _,x:=range deck {
		if _, ok := mp[x]; ok {
			mp[x] += 1
		} else {
			groups += 1
			mp[x] = 1
		}
	}
	minC:=math.MaxInt32
	for _,v:=range mp{
		if v<minC{
			minC=v
		}
	}
	if minC<2{
		return false
	}
	for i:=2;i<=minC;i++{
		if minC%i==0{
			cg:=0
			for _,v:=range mp{
				if v%i==0{
					cg++
				}
			}
			if cg==groups{
				return true
			}
		}
	}
	return false
}
```