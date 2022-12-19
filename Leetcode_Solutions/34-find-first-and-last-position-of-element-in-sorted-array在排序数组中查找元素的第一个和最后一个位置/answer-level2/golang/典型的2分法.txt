### 解题思路
典型的2分法


### 代码

```golang

func searchRange(nums []int, target int) []int {
//首位两个变量
	x:=0
	y:=len(nums)-1
	ret:=[]int{-1,-1}
	for (y>=x){
//遍历，直到中间点
		if nums[x]!=target{
			x++
		}else {
			ret[0]=x
		}
		if nums[y]!=target{
			y--
		}else{
				ret[1]=y		
		}
		if ret[0]!= -1 && ret[1]!=-1{
			break
		}
	}
	return ret
}
```