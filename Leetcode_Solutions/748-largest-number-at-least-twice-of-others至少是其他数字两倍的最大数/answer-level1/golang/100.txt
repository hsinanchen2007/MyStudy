### 解题思路
此处撰写解题思路

### 代码

```golang
func dominantIndex(nums []int) int {
	if len(nums)==0{
		return -1
	}
	max:=nums[0]
	index:=0
	for i:=1;i< len(nums);i++{
		if nums[i]>max{
			max=nums[i]
			index=i
		}
	}
	nums=append(nums[:index],nums[index+1:]...)

	for i:=0;i< len(nums);i++{
		if nums[i]>max/2{
			return -1
		}
	}
	return index
}
```