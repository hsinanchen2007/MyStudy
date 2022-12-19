### 解题思路
打卡

### 代码

```golang
func sortArray(nums []int) []int {
    HeapSort(nums)
    return nums
}

func HeapSort(list []int) {
	length := len(list)
	//建立初始堆
	sift(list, 0, length-1)
	for idx := length / 2; idx >= 0; idx-- {
		// 从后往前调整
		sift(list, idx, length-1)
	}
	// 将大根堆的根节点和堆最后一个元素交换，重新对前面的 length - 1 调整堆
	for idx := length - 1; idx >= 1; idx-- {
		list[0], list[idx] = list[idx], list[0]
		sift(list, 0, idx-1)
	}
	// 结果就是逆序输出大根堆
}

func sift(list []int, left, right int) {
	fIdx := left
	sIdx := fIdx*2 + 1
	// 构造大根堆
	for sIdx <= right {
		//判断左孩子:sIdx 右孩子:sIdx+1
		if sIdx < right && list[sIdx] < list[sIdx+1] {
			sIdx++
		}
		// 最终和大的儿子比较
		if list[fIdx] < list[sIdx] {
			// 交换
			list[fIdx], list[sIdx] = list[sIdx], list[fIdx]
			// 交换后重新检查被修改的子节点为大根堆
			fIdx = sIdx
			sIdx = 2*fIdx + 1
		} else {
			// 已经是大根堆
			break
		}
	}
}
```