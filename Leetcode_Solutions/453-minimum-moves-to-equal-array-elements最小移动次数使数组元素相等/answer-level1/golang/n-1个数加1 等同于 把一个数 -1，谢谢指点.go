### 解题思路
此处撰写解题思路

### 代码

```golang
func minMoves(nums []int) int {//n-1个数加1 等同于把1个数减一
	count:=0
	sort.Ints(nums)

	for i:=1;i< len(nums);i++{
		count+=nums[i]-nums[0]
	}
    // if len(nums)<=1{
	// 	return count
	// }
	// for nums[0]!=nums[len(nums)-1]{
	// 	for i:=0;i< len(nums)-1;i++{
	// 		nums[i]+=1
	// 	}
	// 	count+=1
	// 	sort.Ints(nums)
	// 	fmt.Println(nums)
	// }暴力解法
	return count
}
```