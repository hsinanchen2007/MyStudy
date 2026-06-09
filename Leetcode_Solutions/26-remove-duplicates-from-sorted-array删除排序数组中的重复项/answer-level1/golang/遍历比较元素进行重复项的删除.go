### 解题思路
首先考虑对于数组进行遍历，这是第一层的for循环，然后遍历过程当中，对当前元素所在位置之前的元素进行比较，如果出现了相同的元素，则将当前的元素从数组中移除，移除之后数组长度产生了变化，所以需要减一，然后从已经当前位置重新对前面的元素进行对比，否则会忽略新数组中当前位置的元素。

### 代码

```golang
func removeDuplicates(nums []int) int {

     for i := 1; i < len(nums); i++ {

		for j := 0; j < i; j++ {

			if nums[i] == nums[j] {
				nums = append(nums[:i], nums[i+1:]...)
                i--
			}
		}
	}

	return len(nums)

}
```