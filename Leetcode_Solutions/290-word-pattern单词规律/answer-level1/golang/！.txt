### 解题思路
此处撰写解题思路

### 代码

```golang
func wordPattern(pattern string, str string) bool {
	x:=[]byte(pattern)

	y:=strings.Fields(str)
	if len(x)!= len(y){
		return false
	}
	mapX:=make(map[byte]int)
	mapY:=make(map[string]int)
	for i:=0;i< len(x);i++{
		if _,ok:=mapX[x[i]];!ok{
			mapX[x[i]]=i
		}
		if _,ok:=mapY[y[i]];!ok{
			mapY[y[i]]=i
		}
	}
	for i:=0;i< len(x);i++{
		if mapX[x[i]]!=mapY[y[i]]{
			return false
		}
	}
	return true
}
```