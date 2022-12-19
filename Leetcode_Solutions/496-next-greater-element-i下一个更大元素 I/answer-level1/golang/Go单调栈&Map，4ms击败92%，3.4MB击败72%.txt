### 解题思路
此处撰写解题思路
单调栈Top加上哨兵不用判断是否空
1. 遍历nums2进入单调栈，大于栈顶，更新进dataMap，并出栈
2. 小于栈顶，入栈
3. 遍历nums1赋值，存在Map则赋值，不存在则为-1
### 代码

```golang
func nextGreaterElement(nums1 []int, nums2 []int) []int {
	if len(nums2) <= 1 {
		for i := 0; i < len(nums1); i++ {
			nums1[i] = -1
		}
		return nums1
	}
	dataMap := map[int]int{}
	minStack := NewStack(len(nums2))
	for i := 0; i < len(nums2); i++ {
		// 大于栈顶，更新进dataMap，并出栈
		top := minStack.Top()
		for nums2[i] > top {
			dataMap[top] = nums2[i]
			minStack.Pop()
			top = minStack.Top()
		}
		// 小于栈顶，入栈
		minStack.Push(nums2[i])
	}
	// 遍历nums1赋值
	for i := 0; i < len(nums1); i++ {
		if val, ok := dataMap[nums1[i]]; ok {
			nums1[i] = val
		} else {
			nums1[i] = -1
		}
	}
	return nums1
}

type Stack struct {
	data []int
	length int
}

func NewStack(cap int) Stack {
	return Stack{make([]int, cap), 0}
}

func (s *Stack) Top() int {
	if s.length == 0 {
		return math.MaxInt64	// 哨兵。所有入栈的都会小于它，相当于空栈，新数据直接入栈
	}
	return s.data[s.length-1]
}

func (s *Stack) Push(val int) {
	s.data[s.length] = val
	s.length++
}

func (s *Stack) Pop() {
	s.length--
}
```