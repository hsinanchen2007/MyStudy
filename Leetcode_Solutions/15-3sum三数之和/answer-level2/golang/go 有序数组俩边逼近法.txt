```
var res [][]int
	if len(nums)==0{
		return res
	}
	//题目要求a+b+c=0
	sort.Ints(nums)//先把数组排序
	for a:=0;a<len(nums)-1;a++{//先取一个a
		if a>0&&nums[a]==nums[a-1]{
			continue
		}
		b,c:=a+1,len(nums)-1//b和c分别从除去a之后的子数组中取，b从左边最小位开始，c从右边最大开始
		for b<c{//边界条件
			d:=nums[a]+nums[b]+nums[c]//计算三个值的和
			if d>0{//如果和大于0，c减小，因为c是大值
				c-=1
			}else if d<0{//如果和小于0，b增加，因为b是小值
				b+=1
			}else {
				nm:=[]int{nums[a],nums[b],nums[c]}
				res=append(res,nm)
				for b<c && nums[b]==nums[b+1]{
					b+=1
				}
				for b<c && nums[c]==nums[c-1]{
					c-=1
				}
				b+=1
				c-=1
			}
		}
	}
	return res
```
