### 解题思路
此处撰写解题思路
start:=0
	end:= len(nums)-1
	mid:=(start+end)/2

start=mid+1

### 代码

```golang
func search(nums []int, target int) int {
	start:=0
	end:= len(nums)-1
	mid:=(start+end)/2
	for start<=end{
		if nums[mid]==target{
			return mid
		}
		if target>nums[mid]{
			start=mid+1
			mid=(start+end)/2
		}
		if target<nums[mid]{
			end=mid-1
			mid=(start+end)/2
		}
	}
	return -1
}

```