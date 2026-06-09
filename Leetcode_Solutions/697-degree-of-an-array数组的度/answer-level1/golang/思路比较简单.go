### 解题思路
此处撰写解题思路

### 代码

```golang
func findShortestSubArray(nums []int) int {
    //全部放入map中
	numMap:=make(map[int]int)
	for _,v:=range nums{
		if _,ok:=numMap[v];ok{
			numMap[v]++
		}else{
			numMap[v]=1
		}
	}
	count:=0
	key:=make([]int,0)
    //遍历map寻找 value的最大值
	for _,v:=range numMap{
		if count<v{
			count=v
		}
	}
    //寻找所有value等于最大值的 key
	for k,v:=range numMap{
		if v==count{
			key= append(key, k)
		}
	}
    //计算每个key的最小长度，并取其中长度最小者返回
	return helpFindShortestSubArray(nums,key)
}

func helpFindShortestSubArray(nums []int,key []int)int{
	n:=make([]int, len(key))
	for l,v:=range key{
		x:=0
		for i:=0;i< len(nums);i++{
			if nums[i]==v{
				x=i
				break
			}
		}
		y:=0
		for i:= len(nums)-1;i>=0;i--{
			if nums[i]==v{
				y=i
				break
			}
		}
		n[l]=y-x+1
	}
	if len(n)==0{
		return 0
	}
	tmp:=n[0]
	for i:=1;i< len(n);i++ {
		if tmp>n[i]{
			tmp=n[i]
		}
	}
	
	return tmp
}
```