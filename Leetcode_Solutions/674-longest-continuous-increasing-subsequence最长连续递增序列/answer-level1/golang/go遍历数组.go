### 解题思路
此处撰写解题思路

### 代码

```golang
func findLengthOfLCIS(nums []int) int {
	res:=0
	count:=0
	if len(nums)==0{
		return 0
	}
	//这个for循环只遍历到了 len(nums)-2
	for i:=0;i< len(nums)-1;i++{

		if nums[i]<nums[i+1]{
			count++
		}else{
			//当i大于后面一个数的时候，此时i本身还是算在递增序列中 count要加1
			count++
			if res<count{
				res=count
			}
			count=0
		}
	}
	//最后count还要加1，因为 还有nums[len(nums)-1]没有遍历到，由于这个数字是最后一个数，所以默认满足递增要求
	count++
	if res<count{
		res=count
	}
	return res
}

```