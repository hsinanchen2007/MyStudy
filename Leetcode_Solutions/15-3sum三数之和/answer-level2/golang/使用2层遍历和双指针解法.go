### 解题思路
####使用2层遍历和双指针解法
1. 先将数组进行升序
2. 遍历数组，当作第一个数
3. 双指针获取剩余的两个数
### 代码

```golang
func threeSum(nums []int) [][]int {
	var res [][]int
	sort.Ints(nums)  // 数组排序
	fmt.Println(nums)
	for i, v := range nums {
		temp := nums[i+1:]
		if i-1 >= 0 && nums[i] == nums[i-1] { //跳过重复值
			continue
		}
		l, r := 0, len(temp)-1
		for a := 0; a < len(temp); a++ {
			if l >= r { // 左右指针相遇结束循环
				break
			}
			sum := v + temp[l] + temp[r]
			if sum > 0 { // 和大于0，移动右指针可以使和变小
				r--
			}
			if sum < 0 { // 和小于0，移动左指针可以使和变大
				l++
			}
			if sum == 0 {
				res = append(res, []int{v, temp[l], temp[r]})
				for l < r && temp[r] == temp[r-1] { //跳过重复值: 注意使用循环跳过多个重复值
					r--
				}
				for l < r && temp[l] == temp[l+1] { //跳过重复值：注意使用循环跳过多个重复值
					l++
				}
				l++
				r--
			}
		}
	}
	return res
}
```