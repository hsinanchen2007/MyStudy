### 解题思路
此处撰写解题思路

### 代码

```golang
func findErrorNums(nums []int) []int {
	numMap:=make(map[int]int)
	a:=0
	b:=0
	for _,v:=range nums{
		if _,ok:=numMap[v];ok{
			numMap[v]++
			a=v
		}else{
			numMap[v]=1
		}
	}
	for i:=1;i<= len(nums);i++{
		if _,ok:=numMap[i];!ok{
			b=i
			break
		}
	}
	return []int{a,b}
}
```