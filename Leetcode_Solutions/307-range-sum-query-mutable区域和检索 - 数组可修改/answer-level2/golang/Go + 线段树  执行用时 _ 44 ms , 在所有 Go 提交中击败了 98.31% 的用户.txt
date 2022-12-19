### 解题思路
深度优先搜索，树的遍历 

### 代码

```golang
type NumArray struct {
	value  []int
	length int
}

func Constructor(nums []int) NumArray {
	n := len(nums) * 4
	value := make([]int, n)
	buildSegmentTree(value, nums, 0, 0, len(nums)-1)
	return NumArray{value: value, length: len(nums) - 1}
}

func (this *NumArray) Update(i int, val int) {
	UpdateSegmentTree(this.value, 0, 0, this.length, i, val)
}

func (this *NumArray) SumRange(i int, j int) int {
	return SumRangeSegmentTree(this.value, 0, 0, this.length, i, j)
}

// value 为线段树  pos为线段树的index，用数组表示的二叉树
// 后序遍历，左右根
func buildSegmentTree(value []int, nums []int, pos, left, right int) {
	if len(nums) == 0 {
		return
	}
	// 终止条件  叶子节点
	if left == right {
		value[pos] = nums[left]
		return
	}
	mid := (left + right) / 2
	// 左右子树

	buildSegmentTree(value, nums, pos*2+1, left, mid)
	buildSegmentTree(value, nums, pos*2+2, mid+1, right)
	value[pos] = value[pos*2+1] + value[pos*2+2]
}

func SumRangeSegmentTree(value []int, pos, left, right, qleft, qright int) int {
	if len(value) == 0 {
		return 0
	}
	// 要搜索的区间和当前节点表示的区间没有交集
	if qleft > right || qright < left {
		return 0
	}
	if qleft <= left && qright >= right {
		return value[pos]
	}
	mid := (left + right) / 2
	return SumRangeSegmentTree(value, pos*2+1, left, mid, qleft, qright) +
		SumRangeSegmentTree(value, pos*2+2, mid+1, right, qleft, qright)
}

// 后序遍历，左右根  index表示数组的位置
func UpdateSegmentTree(value []int, pos, left, right, index, newvalue int) {
	if len(value) == 0 {
		return
	}
	if left == right && left == index {
		value[pos] = newvalue
		return
	}
	mid := (left + right) / 2
	if index <= mid {
		UpdateSegmentTree(value, pos*2+1, left, mid, index, newvalue)
	} else {
		UpdateSegmentTree(value, pos*2+2, mid+1, right, index, newvalue)
	}
	value[pos] = value[pos*2+1] + value[pos*2+2]
}

```