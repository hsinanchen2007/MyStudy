### 解题思路
双指针 + 位运算判断数字奇偶性(学习[@jyd](/u/jyd/))大佬

### 知识点：双指针 + 位运算判断数字奇偶性

### 代码

```golang
func exchange(nums []int) []int {
    i, j := 0, len(nums) - 1

	for i < j {
		for i < j && nums[i] & 1 == 1 {  // 从左往右，遇到奇数继续走
			i++
		}

		for i < j && nums[j] & 1 == 0 {  // 从右往左，遇到偶数继续走
			j--
		}

		nums[i], nums[j] = nums[j], nums[i]  // 奇、偶 交换
	}

	return nums
}

// 主函数
func main() {
	nums := []int{1, 2, 3, 4}
	fmt.Println(exchange(nums))
}
```