### 解题思路
此处撰写解题思路

### 代码

```golang
func nextGreaterElement(nums1 []int, nums2 []int) []int {
	for i:=0;i< len(nums1);i++{
		x:=nums1[i]
		var index int
		for j:=0;j< len(nums2);j++{
			if nums2[j]==x{
				index=j
				break
			}
		}
		value:=-1
		for k:=index+1;k< len(nums2);k++{
			if nums2[k] > x{
				value=nums2[k]
				break
			}
		}
		nums1[i]=value
	}
	return nums1
}
```