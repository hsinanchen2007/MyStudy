### 解题思路

建立一个切片来存放每个数字出现的次数，找出出现两次的数字和出现0次的数字即可。

### 代码

```golang
func findErrorNums(nums []int) []int {
	res1,res2 := 0,0
	tmp := make([]int,len(nums) + 1)
	for i := 0;i < len(nums);i++ {
		tmp[nums[i]]++
	}
	for j := 1;j < len(tmp);j++ {
		if tmp[j] == 2 {
			res1 = j
		}
		if tmp[j] == 0 {
			res2 = j
		}
	}
	return []int{res1,res2}
}
```