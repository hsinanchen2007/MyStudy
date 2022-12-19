### 解题思路
此处撰写解题思路

### 代码

```golang
func maxDistToClosest(seats []int) int {
	N:= len(seats)
	res:=0
	count:=0
	for i:=0;i<N;i++{
		// 第1位 count为 1 说明 第0位是0 也就是说 [:i]全部为0
		if i==count{
			res=count
		}else{
			res=int(math.Max(float64(res),float64((count+count%2)/2)))
		}
		if seats[i]==1{
			count=0
		}else{
			count++
		}
	}

	//如果最后一位是0，那么就需要校验 最后的count是不是大于之前的 res 
	if res<count{
		return count
	}
	return res
}
```