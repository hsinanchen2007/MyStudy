### 解题思路
此处撰写解题思路

### 代码

```golang
func hasGroupsSizeX(deck []int) bool {
	numsMap:=make(map[int]int)
	for _,v:=range deck{
		numsMap[v]++
	}
	counts:=make([]int,0)
	val:=0
	
	for _,v:=range numsMap{
		if v!=val{
			if v<2{
				return false
			}
			counts= append(counts, v)
			val=v
		}
	}

	var gcd func(x,y int)int
	gcd = func (x,y int)int{
		p1,p2:=x,y
		if x<y{
			p1,p2=p2,p1
		}
		if p1%p2==0{
			return p2
		}
		return gcd(p1%p2,p2)
	}

	x:=counts[0]
	for i:=1;i< len(counts);i++{
		y:=counts[i]
		x=gcd(x,y)
		if x<2{
			return false
		}
	}
	return true
}


```