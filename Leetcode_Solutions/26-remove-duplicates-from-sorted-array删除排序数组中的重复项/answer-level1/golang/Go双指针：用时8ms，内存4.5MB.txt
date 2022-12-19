### 思路
快慢的两个双指针比较，如果不一致，则快指针和慢指针都++，知道快指针遍历完毕数组

### 代码

```golang
func removeDuplicates(nums []int) int {
    if len(nums) == 0 {
		return 0
	}

    i := 0
	for j := 1; j < len(nums); j++ {
		if nums[j] != nums[i] {
			i++
			nums[i] = nums[j]
		}
	}
    return i+1
}
```
用时 : 8 ms , 在所有 Go 提交中击败了 96.02% 的用户 
内存消耗 : 4.5 MB , 在所有 Go 提交中击败了 100.00% 的用户