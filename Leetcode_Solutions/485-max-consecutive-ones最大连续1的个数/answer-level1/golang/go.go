### 解题思路
此处撰写解题思路

### 代码

```golang
func findMaxConsecutiveOnes(nums []int) int {
	res:=0
	count:=0
	//flag:=false
	for _,v:=range nums{
		if v==1{
			count+=1
		}else{
			if count>res{
				res=count
			}
			count=0
		}
	}
	//最后一个数字如果是以1结尾，那么就不会比较最后一次的count与 res的大小
	if count>res{
		res=count
	}
	return res
}

```