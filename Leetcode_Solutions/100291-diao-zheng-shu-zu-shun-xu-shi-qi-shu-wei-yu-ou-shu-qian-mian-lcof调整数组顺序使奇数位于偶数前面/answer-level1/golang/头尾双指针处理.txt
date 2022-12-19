### 解题思路
设置`head`和`tail`两个指针，分别指向数组的第一个和最后一个元素。
- 当满足`head`指向元素为偶数，并且`tail`指向元素为奇数的时候，进行交换，并将`head`和`tail`分别指向后一个和前一个元素；
- 当`head`指向元素为奇数的时候，仅将`head`指向后一个数组元素；
- 当`tail`指向元素为奇数的时候，仅将`tail`指向前一个数组元素；
- 如此循环直到`head`和`tail`相邻。

### 代码

```golang
func exchange(nums []int) []int {
	head := 0
	tail := len(nums) - 1
	for head < tail {
		if nums[head]%2 == 0 && nums[tail]%2 == 1 {
			nums[head], nums[tail] = nums[tail], nums[head]
			head++
			tail--
		}
		if nums[head]%2 == 1{
			head++
		}
		if nums[tail]%2 == 0{
			tail--
		}
	}

	return nums
}
```