### 解题思路
递归的思路求解
![image.png](https://pic.leetcode-cn.com/211c3d5db6c3ca309cac48b3c29195a32f19452338cb1b513c2c078bb660e37d-image.png)


### 代码

```golang
func PermHelper(nums []int, k, m int, permList *[][]int) {
	if k == m {
		*permList = append(*permList, nums)
	} else {
		for i := k; i <= m; i++ {
			nums[i], nums[k] = nums[k], nums[i]
			cnums := make([]int, len(nums))
			copy(cnums, nums)
			PermHelper(cnums, k+1, m, permList)
			nums[i], nums[k] = nums[k], nums[i]
		}
	}
}

func permute(nums []int) [][]int {
	permList := make([][]int, 0)
	PermHelper(nums, 0, len(nums)-1, &permList)
	return permList
}
```