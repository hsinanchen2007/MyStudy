### 解题思路

将nums1和nums2两个数组中共有的无重复的放在第三个数组中就行了

### 代码

```golang
func intersection(nums1 []int, nums2 []int) []int {
	result := []int{}
	
	for i:=0;i < len(nums1);i++ {
		if contains(nums2,nums1[i]) && !contains(result,nums1[i]){
			result = append(result,nums1[i])
		}
	}
	return result
}
func contains(a []int,b int) bool {
	for i:=0;i<len(a);i++ {
		if a[i] == b {
			return true
		}
	}
	return false
}
```