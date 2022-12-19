### 解题思路
此处撰写解题思路

### 代码

```golang
func permute(nums []int) [][]int {
	result:=make([][]int,0)
	t:=make([]int,0)
	dfs1(nums,0,0,t,&result)
	return result
}


func dfs1(nums []int,start int,cnt int,t []int,r *[][]int){
	if len(t) == len(nums){
		tmp:=make([]int,len(t))
		copy(tmp,t)
		*r=append(*r,tmp)
		return
	}
	
	for i:=start;i<len(nums);i++{
		if isExist(nums[i],t){
			continue
		}
		t=append(t,nums[i])
		//fmt.Printf("i:%v,t:%v\n",i,t)
		dfs1(nums,0,cnt,t,r)
		t=t[:len(t)-1]
	}
}

func isExist(v int, t []int)bool{
	for i:=0;i<len(t);i++{
		if v == t[i]{
			return true
		}
	}
	return false 
}
```