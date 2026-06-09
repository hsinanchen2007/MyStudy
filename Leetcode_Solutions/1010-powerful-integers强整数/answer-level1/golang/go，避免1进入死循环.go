### 解题思路
此处撰写解题思路

### 代码

```golang
func powerfulIntegers(x int, y int, bound int) []int {
	xNums:=make([]int,0)
	yNums:=make([]int,0)
    //注意考虑1的情况，避免进入死循环
	if x==1{
		xNums= append(xNums, 1)
	}else{
		for i:=0;math.Pow(float64(x),float64(i))<=float64(bound);i++{
			xNums= append(xNums, int(math.Pow(float64(x),float64(i))))
		}
	}
	if y==1{
		yNums= append(yNums, 1)
	}else{
		for i:=0;math.Pow(float64(y),float64(i))<=float64(bound);i++{
			yNums= append(yNums, int(math.Pow(float64(y),float64(i))))
		}
	}
	
	resMap:=make(map[int]bool)
	for i:=0;i< len(xNums);i++{
		for j:=0;j< len(yNums);j++{
			if xNums[i]+yNums[j]<=bound{
				resMap[xNums[i]+yNums[j]]=true
			}
		}
	}
	res:=[]int{}
	for k,_:=range resMap{
		res= append(res, k)
	}
	return res
}
```