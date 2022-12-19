### 解题思路
 遍历一遍 执行用时 : 4 ms , 在所有 Go 提交中击败了 95.85% 的用户
两个指针，通过j标记0的位置，将非0的元素与前面第一个0的元素交换

	i
1 0 2 3 
  j 
（此时i j交换）
### 代码

```golang
func moveZeroes(nums []int) {
	j := -1
	for i := 0; i < len(nums); i++ {
		// 初始化第一个0的位置
		if j == -1 && nums[i] == 0 {
			j = i
		}
		if j != -1 && nums[i] != 0 {
			nums[j], nums[i] = nums[i], nums[j]
			j++
		}
	}
}

```