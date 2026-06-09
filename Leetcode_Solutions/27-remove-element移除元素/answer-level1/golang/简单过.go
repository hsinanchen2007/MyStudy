### 解题思路
直接同26题的解法就可以了。末尾元素向前置换的写法，运行的效率是一样的。

执行用时 :0 ms, 在所有 Go 提交中击败了100.00% 的用户
内存消耗 :2.1 MB, 在所有 Go 提交中击败了12.22%的用户

### 代码

```golang
func removeElement(nums []int, val int) int {
	/* 同26题解法
	end := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] != val {
			nums[end] = nums[i]
			end++
		}
	}
	return end
	*/
	i, n := 0, len(nums)
	for i < n {
		if nums[i] == val {
			nums[i] = nums[n-1]
			n--
		} else {
			i++
		}
	}
	return n
}
```