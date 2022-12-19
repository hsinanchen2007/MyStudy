

```go
package lt84

import (
	"math"
	"sort"
)

// 柱状图中最大的矩形
// n个非负整数，表示柱状图中柱高，每个柱子宽度为1
// 求能勾勒出的矩形的最大面积

// 这题和装水容器、接雨水比较像，都是左右双指针内移的套路

// 根据题意
// 矩形有两类情况
// 1. 取heights最小值，以heights长度为宽，所得矩形面积为area1
// 2.
// 要取最大矩形面积 s=b(宽)*h(高) ，则肯定先取其中一边 b 为max，再将 b 慢慢缩小，h则尝试向增大的方向变化，才可能找到最大矩形面积
// 这里h是宽度范围里的最小值，当b缩小时，需要更新h值

// 当区间内包含 minHeight 时， h 必定为 min， 再怎么移动左右指针都不可能增大矩形面积， 所以每次都要寻找最小值
// 假设一开始heights有最小值nums[min]，其下标min，此时矩形值为 s0 = len(heights) * nums[min]
// 计算左半区间(不含min)的新最小值min1，并计算新的矩形值s1 = min * min1，
// 如果 s1 <= s0， 则左边，重复前边的操作：按min1分成新的两个区间，再去计算
// 如果 s1 > s0， 更新 maxS = s1, 并在 min1 左右分成两个区间看能不能找到更大的面积
// 从这个分析来看，适合递归求解


// 1. 自己给出的递归分治解法
// 不考虑内层寻找最小值的情况的话。外层其实类似二分查找，时间复杂度应该是O(logn)，但恶化的情况下会变成O(n)
// 而每一次findMaxArea都要O(n)时间。
// 时间O(nlogn),空间O(n)
//96/96 cases passed (664 ms)
//Your runtime beats 31.25 % of golang submissions
//Your memory usage beats 7.14 % of golang submissions (7.2 MB)
func largestRectangleArea1(heights []int) int {

	// 1. 特殊情况
	l := len(heights)
	if l==0 {return 0}
	if l==1 {return heights[0]}

	// 2. 一般情况
	var maxArea int
	findMaxArea(heights, &maxArea)
	return maxArea
}

func findMaxArea(ints []int, maxArea *int) {
	l := len(ints)
	if l==0 {return}	// 当ints没有数之时返回
	minI, minV := minInInts(ints)
	area := l * minV
	if area > *maxArea {*maxArea = area}	// 更新最大面积
	// 将区间一分为二再计算
	if minI != 0 || minI != l-1 {
		findMaxArea(ints[:minI], maxArea)
		findMaxArea(ints[minI+1:], maxArea)
	} else if minI == 0 {
		findMaxArea(ints[1:], maxArea)
	} else if minI == len(ints)-1 {
		findMaxArea(ints[:l-1], maxArea)
	}

}

// 这里是采用一次扫描的办法取最小值，但这样显然浪费了许多计算，先这样写着
func minInInts(ints []int) (index, value int) {
	value = math.MaxInt32
	for i:=0; i<len(ints); i++ {
		if ints[i] < value {
			index, value = i, ints[i]
		}
	}
	return index, value
}


// 分析前面解法，可以知道，想要找到最大矩形面积， 解法1前面的外层递归是不可避免的，总要比对这么多次数
// 时间的优化点在 minInInts 函数上想办法优化
// 可以想到： 利用栈操作来优化最小值的寻找。

// 此外，当数组本身有序的话，上面的思路分治一点优化作用也没有，因为每次都要在一个O(n)级别的数组里找最小值
// 因此最坏情况下时间复杂度变成了O(n^2)

// 从这里开始，参考官方题解。
// 1. 暴力解： 利用两个指针从左向右滑移(内外两层遍历)计算所有情况下的矩形面积， O(n^3)的时间复杂度（查找最小高度需O(n)），空间O(1)
// 2. 优化暴力 利用前一对柱子之间的最低高度来求出当前柱子间的最低高度 minHeight = min( minheight, heights[j] )  时间O(n^2)，空间O(1)
// 3. 分治解法 思路与我前面的解法一般。
// 4. 优化的分治解法 官方题解这里用线段树代替遍历寻找区间最小值，单词查询复杂度变成O(logn)，空间因为使用了线段树，占用O(n)
// 5. 使用栈


// 2. 基于栈的解法
//时间复杂度：O(n)。 n 个数字每个会被压栈弹栈各一次。
//空间复杂度： O(n)。用来存放栈中元素。
//96/96 cases passed (12 ms)
//Your runtime beats 78.15 % of golang submissions
//Your memory usage beats 57.14 % of golang submissions (4.8 MB)
func largestRectangleArea2(heights []int) int {

	l := len(heights)

	if l == 0 {return 0}
	if l == 1 {return heights[0]}

	// 用切片模拟栈，为了节省切片扩容时间，预设切片空间为数组长度
	// 栈用来存heights数组中元素下标
	stack := make([]int, 1, l)
	stack[0] = -1		// 预填一个-1

	maxArea := 0
	var area int
	for i:=0; i<l; i++ {
		for stack[len(stack)-1] != -1 && heights[ stack[len(stack)-1] ] >= heights[i] {
			area = heights[stack[len(stack)-1]] * (i - stack[len(stack)-2] - 1)
			if area > maxArea {maxArea = area}
			stack = stack[:len(stack)-1]
		}
		stack = append(stack, i)
	}

	for stack[len(stack)-1] != -1 {		// 栈未到底
		area = heights[stack[len(stack)-1]] * (l - stack[len(stack)-2] - 1)
		if area > maxArea {maxArea = area}
		stack = stack[:len(stack)-1]
	}
	return maxArea
}


// 从这里重新梳理此题
// 参照 windliang 题解

// 3. 暴力解法
// 遍历整个heights，当遍历到heights[i]时，看包含heights[i]在内的连续的>=heights[i]的柱子有多少
// 若有 n 个，则矩形宽即为 n ， 则 S = heights[i] * n
// 如果每次都去找的话需要 O(n^2)时间， O(1)空间
// 如果再对heights作去重，使用哈希集合记录不重复高度，则空间占用O(n)
//96/96 cases passed (248 ms)
//Your runtime beats 46.64 % of golang submissions
//Your memory usage beats 50 % of golang submissions (5.3 MB)
func largestRectangleArea3(heights []int) int {

	l := len(heights)

	if l == 0 {return 0}
	if l == 1 {return heights[0]}

	// 得到所有高度值
	heightsSet := make(map[int]bool)
	for i:=0; i<l; i++ {
		heightsSet[heights[i]] = true
	}

	// 遍历每个高度，求出每个高度的矩形的最大宽度
	var area, maxArea int
	for h := range heightsSet {
		width, maxWidth := 0, 1
		// 遍历heights，找连续的柱子
		for i:=0; i<l; i++ {
			if heights[i] >= h {
				width++
			} else {
				// 否则width归零，并更新maxWidth
				if width > maxWidth {maxWidth = width}
				width = 0
			}
		}
		// width若一直不归零，需要这句保证maxWidth有值
		if width > maxWidth {maxWidth = width}
		// 更新maxArea
		area = maxWidth * h
		if area > maxArea {maxArea = area}
	}
	return maxArea
}

// 4. 以heights中min作为分界线，将区间分为左右，不停递归下去。这个思路就是我自己解的，也就是解法1
// 在这个思路下限制时间复杂度的在于寻找数组最小值。由于heights数组是不变的，所以可以使用一个数据结构去记录所有可能的min
// 这个数据结构是 线段树
// 应用了线段树之后，空间占用O(n)，min查找时间复杂度O(logn)，总体时间变成O(nlogn)
//

// =====================线段树

type Node struct {
	Start, End int	// 区间的左右断电
	MinI, MinV int	// 区间内的最小值的下标和值
}

func NewNode(start, end int) *Node {
	return &Node{Start:start, End:end}
}

type SegmentTree struct {
	base []int
	Nodes []*Node
}

func NewSegmentTree(nums []int) *SegmentTree {
	st := &SegmentTree{
		base:  make([]int, len(nums)),
		Nodes: make([]*Node, 4 * len(nums)),
	}
	copy(st.base, nums)
	return st
}


func (st *SegmentTree) Build(index int) {
	// 取出index所指的线段树节点
	node := st.Nodes[index]
	if node==nil {	// 根节点需要手动创建
		st.Nodes[index] = NewNode(0, len(st.base)-1)
		node = st.Nodes[index]
	}
	if node.Start == node.End {		// 叶子节点
		node.MinI, node.MinV = node.Start, st.base[node.Start]
	} else {			// 不是叶节点，则要递归构建其左右子树
		mid := (node.Start + node.End) >> 1
		st.Nodes[index << 1 + 1] = NewNode(node.Start, mid)		// 左子节点
		st.Nodes[index << 1 + 2] = NewNode(mid+1, node.End)		// 右子节点
		st.Build(index << 1 + 1)		// 左子树
		st.Build(index << 1 + 2)		// 右子树
		if st.Nodes[index << 1 + 1].MinV <= st.Nodes[index << 1 + 2].MinV {
			node.MinI, node.MinV = st.Nodes[index << 1 + 1].MinI, st.Nodes[index << 1 + 1].MinV
		} else {
			node.MinI, node.MinV = st.Nodes[index << 1 + 2].MinI, st.Nodes[index << 1 + 2].MinV
		}
	}
}

func (st *SegmentTree) Query(index, start, end int) *Node {
	node := st.Nodes[index]
	if node.Start > end || node.End < start {
		// 查询区间与当前节点所代表区间(index所对应区间)没有交集
		return nil
	}
	if node.Start >= start && node.End <= end {
		// 当前节点区间完全处于待查询区间内，则直接返回Node
		return node
	}

	// 查询左右子树
	leftMinV, rightMinV := math.MaxInt32, math.MaxInt32
	left := st.Query(index << 1 + 1, start, end)
	if left != nil {leftMinV = left.MinV}
	right := st.Query(index << 1 + 2, start, end)
	if right != nil {rightMinV = right.MinV}

	if leftMinV <= rightMinV {
		return left
	} else {
		return right
	}
}

// ====================== 基于线段树的 解法1 优化

//96/96 cases passed (40 ms)
//Your runtime beats 47.06 % of golang submissions
//Your memory usage beats 7.14 % of golang submissions (11.9 MB)
func largestRectangleArea4(heights []int) int {
	l := len(heights)
	if l == 0 {return 0}
	if l == 1 {return heights[0]}

	// 构造线段树
	st := NewSegmentTree(heights)
	st.Build(0)

	// 递归分治， 查找最大面积
	return getMaxArea(st, 0, l-1)
}

func getMaxArea(st *SegmentTree, start, end int) int {
	if start == end {return st.base[start]}
	if start > end {return math.MinInt32}	// 非法处理
	// 找出最小柱子的下标
	minI := st.Query(0, start, end).MinI
	// 最大矩形区域在包含选定柱子的区域
	areas := make([]int, 3)
	areas[0] = st.base[minI] * (end - start + 1)
	areas[1] = getMaxArea(st, start, minI-1)
	areas[2] = getMaxArea(st, minI+1, end)
	sort.Ints(areas)	// 升序排列
	return areas[2]
}


// 5. 解法1和解法4中是利用min将区间分开然后递归分治。
// 它们的时间复杂度是O(nlogn)，但是当heights越接近有序时会退化至O(n^2)
// 这是因为若min越偏离中间，左右分段就会越来越没有效果，复杂度会越高
// 如果每次都能保证左右均分，那么能够保证稳定的 O(nlogn)
//
// 思路见 题解区 windliang 解法三

// 空间O(logn)
//96/96 cases passed (16 ms)
//Your runtime beats 52.1 % of golang submissions
//Your memory usage beats 25 % of golang submissions (6 MB)
func largestRectangleArea5(heights []int) int {
	l := len(heights)
	if l == 0 {return 0}
	if l == 1 {return heights[0]}

	return getMaxArea5(heights, 0, l-1)
}

func getMaxArea5(heights []int, start, end int) int {
	if start == end {return heights[start]}
	mid := start + (end - start) / 2
	areas := make([]int, 3)
	// 左半部分
	areas[0] = getMaxArea5(heights, start, mid)
	areas[1] = getMaxArea5(heights, mid+1, end)
	areas[2] = getMidArea5(heights, start, mid, end)
	sort.Ints(areas)	// 升序排列
	return areas[2]
}

func getMidArea5(heights []int, start, mid, end int) int {
	i, j := mid, mid+1
	minH := heights[i]
	if heights[j] < heights[i] {minH = heights[j]}
	area := minH * 2	// 中间两根柱子形成的矩形面积

	// 向两端扩展。 贪婪思想
	var minH1, area1 int
	for i>=start && j<=end {	// 在区间内
		// 计算并更新minH
		minH1 = heights[i]
		if heights[j] < heights[i] {minH1 = heights[j]}
		if minH1 < minH {minH = minH1}

		// 更新最大面积
		area1 = minH * (j-i+1)
		if area1 > area {area = area1}

		// 贪婪扩展
		if i==start {
			j++
		} else if j==end {
			i--
		// 向较高柱子的方向扩展
		} else if heights[i-1] >= heights[j+1] {
			i--
		} else {
			j++
		}
	}

	return area
}



// 6.
// 解法三（暴力解法）中是找出heights中所有高度值，找出以各个高度值为矩形高的最大矩形面积，进而取得最大面积
// 这个解法转变思路
// 不对heights元素去重，而是遍历到每一个height，从该height向左右延伸，直至遇到高度比自己低。
// 也就是说，要快速找到向左延伸第一个小的柱子，和向右延伸的第一个小的柱子
// 用一个数组leftFirstLess来记录向左第一个比自己小的柱子
// 向右一样 rightFirstLess
// 怎么找leftFirstLess，从第i根柱子向左寻找呗
// 但是这个过程可以优化一下。
// 如果当前heights[i]比heights[i-1]小，那么leftFirstLess[i]直接从leftFirstLess[i-1]开始向左搜索即可
// 而这又正好是 leftFirstLess[p]
// 这样一来，查询时间复杂度就是O(n)，因为在构建leftFIrstLess时每个元素都只会访问两次
// 这和基于栈的解法本质一样。
// rightFirstLess的构建同理
// 时间O(n)，空间O(n)
//96/96 cases passed (12 ms)
//Your runtime beats 78.15 % of golang submissions
//Your memory usage beats 53.57 % of golang submissions (5.3 MB)
func largestRectangleArea6(heights []int) int {
	l := len(heights)
	if l == 0 {return 0}
	if l == 1 {return heights[0]}

	// 构建leftFirstLess
	var p int
	leftFirstLess := make([]int, l)
	leftFirstLess[0] = -1
	for i:=1; i<l; i++ {
		p = i - 1
		for p>=0 && heights[p] >= heights[i] {
			// p 此时指向的是 leftFirstLess[i-1]
			p = leftFirstLess[p]
		}
		leftFirstLess[i] = p
	}

	// 构建rightFirstLess
	rightFirstLess := make([]int, l)
	rightFirstLess[l-1] = l
	for i:=l-2; i>=0; i-- {
		p = i + 1
		for p<=l-1 && heights[p] >= heights[i] {
			// p 此时指向的是 rightFirstLess[i-1]
			p = rightFirstLess[p]
		}
		rightFirstLess[i] = p
	}

	// 求包含每个柱子的矩形区域的最大面积，从中选出最大者
	var maxArea, area int
	for i:=0; i<l; i++ {
		area = (rightFirstLess[i] - leftFirstLess[i] - 1) * heights[i]
		if area > maxArea {maxArea = area}
	}
	return maxArea
}

// 7. 解法6的基于栈解法
// 在解法6中，将heights[i]对应的leftFirstLess[i]和rightFIrstLess[i]找到，这两个是一对
// 这样的配对问题在lt42接雨水中思路一样
// 遍历heights[i]：
// (1)若栈空或 栈顶柱子高度<当前柱子高度，则将当前柱子的下标入栈
// (2)若栈顶柱子高度>当前柱子高度，就把栈顶出栈，当做解法6中要求矩形面积的柱子
// 而右边第一个小于当前柱子的下标就是当前在遍历的柱子，左边第一个小于当前柱子的下标就是当前新的栈顶
// 遍历完后，若栈没有空，依次出栈，出栈元素当做解法6的要求面积的柱子，然后依次计算矩形面积
//96/96 cases passed (12 ms)
//Your runtime beats 78.15 % of golang submissions
//Your memory usage beats 53.57 % of golang submissions (4.8 MB)
func largestRectangleArea7(heights []int) int {

	l := len(heights)

	if l == 0 {return 0}
	if l == 1 {return heights[0]}

	stack := make([]int, 0, l)
	p := 0
	maxArea := 0
	var area, top, leftFirstLess, rightFirstLess int

	for p<l {
		// 栈空入栈
		if len(stack)==0 {
			stack = append(stack, p)
			p++
		} else {
			// 取当前栈顶
			top = stack[len(stack)-1]
			// 若当前高度>=栈顶则入栈
			if heights[p] >= heights[top] {
				stack = append(stack, p)
				p++
			} else {
				// 否则出栈并且更新maxArea

				// 出栈
				stack = stack[:len(stack)-1]
				// 新栈顶就是解法6中的leftFirstLess
				leftFirstLess = -1
				if len(stack) != 0 {leftFirstLess = stack[len(stack)-1]}
				// 右边第一个小于当前柱子(top)的柱子下标(p)
				rightFirstLess = p
				// 更新最大矩形面积
				area = (rightFirstLess - leftFirstLess - 1) * heights[top]
				if area > maxArea {maxArea = area}
			}
		}
	}

	// 如果栈顶最后非空
	for len(stack) != 0 {
		// 保存当前栈顶
		top = stack[len(stack)-1]
		// 出栈
		stack = stack[:len(stack)-1]
		// 新栈顶就是解法6中的leftFirstLess
		leftFirstLess = -1
		if len(stack) != 0 {leftFirstLess = stack[len(stack)-1]}
		// 右边没有小于当前高度的柱子，所以赋值为heights长度
		rightFirstLess = l
		// 更新最大矩形面积
		area = (rightFirstLess - leftFirstLess - 1) * heights[top]
		if area > maxArea {maxArea = area}
	}

	return maxArea
}

// 总结一下：
// 比较好的解法思路是三类：
// 1. 递归分治 + 线段树优化
// 2. 递归均分 + 贪婪扩张
// 3. 高度匹配 + 数组记录/栈记录
```