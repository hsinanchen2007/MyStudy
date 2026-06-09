### 解题思路
此处撰写解题思路

### 代码

```golang
func findLHS(nums []int) int {
	count:=0
	numMap:=make(map[int]int)
	for _,v:=range nums{
		if _,ok:=numMap[v];ok{
			numMap[v]++
		}else{
			numMap[v]=1
		}
	}
	for i,v:=range numMap{
		
		y:=0
		if x,ok:=numMap[i-1];ok{
			y=x
		}
		z:=0
		if x,ok:=numMap[i+1];ok{
			z=x
		}
		if y!=0||z!=0{
			if y>z&&(v+y)>count{
				count=v+y
			}else if z>y&&(v+z)>count{
				count=v+z
			}
		}
	}
	return count
}
```