### 解题思路
此处撰写解题思路

### 代码

```golang
func longestConsecutive(nums []int) int {
	if len(nums)==0{
		return 0
	}
	sort.Ints(nums)
	maxLen:=0
	preElem:=nums[0]
	tmpLen:=0
	for i:=1;i<len(nums);i++{

		if nums[i]-preElem==1{
			tmpLen++
			preElem=nums[i]
			if tmpLen>maxLen{
				maxLen=tmpLen
			}
		}else if nums[i]-preElem==0{//注意有重复的元素
			preElem=nums[i]
		} else {
			preElem=nums[i]
			tmpLen=0
		}
	}
	return maxLen+1
}

```