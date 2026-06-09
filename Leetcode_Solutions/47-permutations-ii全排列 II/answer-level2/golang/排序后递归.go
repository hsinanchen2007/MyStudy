1、先排序，后递归

这里要求不能有重复排列组合，按15题的方法，排序后能解决重复的问题；
递归的思路是按树形结构进行遍历，如果树中同一层的节点一样，那么它们下面的组合也是一样的（因为元素是排序的，所以剩余的元素也是一样），所以保证在递归的同一层，只能处理一个值的元素即可

```golang
// 冒泡排序，用于后面保证去重
func BubbleSort(nums []int) {
	for i := 0; i < len(nums) - 1; i++ {
		for j := i + 1; j < len(nums); j++ {
			if nums[i] > nums[j] {
				nums[i], nums[j] = nums[j], nums[i]
			}
		}
	}
}

func BuildEveryResult(leftNums, curRes []int, result *[][]int) {
	if len(leftNums) == 1 {
		curRes = append(curRes, leftNums[0])
		*result = append(*result, curRes)
		return
	}

	lastElem := 0
	for i := 0; i < len(leftNums); i++ {
		// 在排序数组中，递归的同一层中只处理一次同一个值
		if i > 0 && leftNums[i] == lastElem {
			continue
		}
		lastElem = leftNums[i]

		newLeft := make([]int, 0)
		for j := 0; j < len(leftNums); j++ {
			if i != j {
				newLeft = append(newLeft, leftNums[j])
			}
		}

		newRes := make([]int, len(curRes) + 1)
		for j := 0; j < len(curRes); j++ {
			newRes[j] = curRes[j]
		}
		newRes[len(curRes)] = leftNums[i]

		BuildEveryResult(newLeft, newRes, result)
	}
}

func permuteUnique(nums []int) [][]int {
	if len(nums) == 0 {
		return nil
	}

	BubbleSort(nums)

	curRes := make([]int, 0)
	result := make([][]int, 0)
	BuildEveryResult(nums, curRes, &result)

	return result
}
```