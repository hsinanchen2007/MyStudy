Golang的同学可以看一下。

强烈推荐解法Sol_1_6 （分治思想，下图是其提交结果），高效又好理解！比较容易想到的是动态规划 + 缓存方案 （Sol_1_3），
基于栈的解法（Sol_1_5）也比较好理解。

![image.png](https://pic.leetcode-cn.com/9c630e63756cb16e4dd7b8f17b7c22f67d9fe7365ddff9e0e614348cc90345be-image.png)


*说实话，双指针法还没理清，下次再好好琢磨*

## 主要参考题解

- <https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/>
- <https://leetcode-cn.com/problems/trapping-rain-water/solution/ke-neng-shi-zui-jian-dan-bao-li-de-jie-fa-by-neil-/>

## 实现

```go
package lt42

import (
	"container/list"
	"math"
)

// 接雨水
// 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出: 6

// 思考：
// 1. 读题后我的第一反应是把这些值看作点，连在一起就是一条离散的“曲线”，
// 找出曲线中的所有局部最大值（连续相等的极大值坍缩为一个点），局部最大值之间的凹陷才能装水
// 那么代码上要实现就是设一个max，min变量，max指针记录极大值，min指针记录极小值，（极大值的发现需要借助极小值），
// 当遍历一遍结束后，将找到的极大值，存到一个数组中去。接着第二次遍历，则按照这个数组的内容去有针对性的遍历，计算凹陷面积，最后所有凹陷面积相加
// 这样的时间复杂度为O(N),空间也为O(N)
// 	(1). 怎么找极大值呢？每个值跟前后两个数作比较，如果比左边大，比右边也大就是一个极大值。
//  (2). 这里其实多比较了一遍，所以还可以通过一个变量标记与前一个数的比较结果。
//  (3). 如果是某个极大值不是一个点而是多个连续点形成线呢？再加一个变量，记录线起始点，找到终止点后，看终止点比终止点后的数大还是小。
// 		大则说明这条线段应该坍缩为一个极大值点， 小则都不是。
// 2. 我想到的第二个思路就是利用在盛水容器一题中get到的双指针向内夹逼的思路了。
// 		l,r指针分别在左数第一个和右数第一个，然后向内移动。什么时候移？怎么移呢？
// 		设给定的数组为h[0:n-1],
// 		(1). 接雨水的初始容量为 area = (n-1)*min(h[0], h[n-1])
//      (2). 假设l比r矮，
//      	(2.1) 那么如果l++比l高，那么area直接更新： area = (n-2)*min(h[1], h[n-1])
// 			(2.2) 如果l++ <= l, 那么 area = area - h[l++]
// 			(2.3) 那么 r 呢？r需要移动吗？怎么移？
// 			(2.4) 如果 r-- 比r 矮 但比 max(l, l++) 高。那么 area = area - max(l, l++)
// 			(2.5) 如果 r-- 比 r 高， 容器内缩，右高增加，需要重新和 l-- 比较
// 		(3) 从这个分析来看，如果两个指针同时移动，会使得比较难理解。要简单还是只使用一根指针移动会比较好实现。

// 现在，开始看优秀题解，并作实现与总结。
// 直接看最高赞，实现如下：

// 1. 按行计算(计算每一行可以存的水，最后再相加)
// 对于每一层，从前向后遍历，当发现某个数比本层的最大值小，那就说明这个地方可以填一份水，也就是 水量+1
// 时间O(n*m)(m最大高度)， 空间O(1)
//315/315 cases passed (1040 ms)
//Your runtime beats 5.07 % of golang submissions
//Your memory usage beats 67.5 % of golang submissions (2.8 MB)
func Sol_1_1(height []int) int {
	var sum int		// 装水量总和
	max := getMax(height)	 // 找到最大高度，以便遍历。 O(n). 也就是说总共需要遍历 max 层

	for i:=1; i<=max; i++ {	// 按行遍历
		isStart := false
		tempSum := 0	// 当前行的存水量
		for j:=0; j<len(height); j++ {
			if isStart && height[j] < i {	//在当前列的左边出现了 isStart 说明“凹陷”可能开始，当前列比左边界矮（证实了“凹陷”）
				tempSum++	// 当前行“凹陷”的一个格子
			}
			if height[j] >= i {		// 当第一次发现有一列比当前行高度高，说明是新的“凹陷”左端（开始），
									// 从isStart到下一个isStart，中间都是“凹陷”，可以填水
				sum = sum + tempSum
				tempSum = 0
				isStart = true
			}
		}
	}

	return sum
}

// 获取全局最大高度
func getMax(height []int) int {
	max := 0
	for _, v := range height {
		if v > max {
			max = v
		}
	}
	return max
}

// 2. 按列求
// 对每一列的水，只需要关注当前列，往左边走最高（leftHigh）以及往右边走最高(rightHigh)即可（注意这个往左/右走的措词）
// 并且装水多少，只取决于 矮边shortSide =  min(leftHIgh, rightHIgh)
// 矮边和当前列 height[i] 的相对关系：
// 		(1) height[i] < shortSIde: 当前列可以存 shortSide - height[i] 的水
//      (2) height[i] >= shortSIde： 当前列不能存水
// 时间O(n2)空间O(1)
//315/315 cases passed (80 ms)
//Your runtime beats 13.29 % of golang submissions
//Your memory usage beats 67.5 % of golang submissions (2.8 MB)
func Sol_1_2(height []int) int {
	var sum, leftHigh, rightHigh, shortHigh int	// sum为装水总量
	for i:=1; i<=len(height)-2; i++ {	// 最左最右两边一定没水
		leftHigh = getHigh(height, i-1, ToLeft)		// 找左边最高列
		rightHigh = getHigh(height, i+1, ToRight)	// 找右边最高列
		shortHigh = min(leftHigh, rightHigh)
		if shortHigh > height[i] {	// 只有当前列比矮边更矮，才可能能装水
			sum = sum + shortHigh - height[i]
		}
	}

	return sum
}

const (
	ToLeft bool = true
	ToRight bool = false
)

// 向左或者向右搜索high（最高列）
func getHigh(height []int, start int, direction_left bool) int {
	high := 0
	if direction_left {		// 向左搜索
		for i:=start; i>=0; i-- {
			high = max(high, height[i])
		}
	} else {	// 向右搜索
		for i:=start; i<len(height); i++ {
			high = max(high, height[i])
		}
	}

	return high
}

// 求最小值
func min(a, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}

// 求最大值
func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

// 3. 动态规划
// Sol_1_2按列求中，每次都重新向左和向右搜索leftHigh和rightHigh。
// 但显然可以将之与height[i]比较，更新leftHigh和rightHigh，去留给Height[i++]用
// 在leetcode高赞题解（作者windliang）中它的动态规划，使用了两个数组去记录刷新的leftHigh[i]和rightHigh[i]。这使用了O(n)的空间。
// 如果这里不使用辅助数组呢？ 而是向我在上两行分析Sol_1_2优化那样，通过直接刷新leftHigh和rightHigh留给height[i++]用。
// 这样做能不能做到时间O(n),空间O(1)？很遗憾，不行，若指针向右移动，左边的leftHigh自然方便更新，但此时右侧的rightHIgh必须要重新进行搜索哦
// 因为这是一个求最大值问题，且搜索区间变小了，必须重新搜索，所以时间复杂度仍然是O(N2)。
// 那么来两次遍历一次向右，一次向左呢？那样对于Height[i]来说为了得到它的位置的leftHIgh和rightHigh，仍然必须用数组存储这些“左高”“右高”
// 所以辅助数组是必不可少的。
//315/315 cases passed (4 ms)
//Your runtime beats 90.82 % of golang submissions
//Your memory usage beats 10 % of golang submissions (3.1 MB)
func Sol_1_3(height []int) int {
	sum, leftHigh, rightHigh, shortHigh := 0, make([]int, len(height)), make([]int, len(height)), 0// sum为装水总量
	for i:=1; i<len(height)-1; i++ {
		leftHigh[i] = max(leftHigh[i-1], height[i-1])		// 计算 leftHigh 数组
	}
	for i:=len(height)-2; i>0; i-- {
		rightHigh[i] = max(rightHigh[i+1], height[i+1])		// 计算 rightHigh 数组
	}
	for i:=1; i<len(height)-1; i++ {
		shortHigh = min(leftHigh[i], rightHigh[i])
		if shortHigh > height[i] {	// 只有当前列比矮边更矮，才可能能装水
			sum = sum + shortHigh - height[i]
		}
	}
	return sum
}

// 4. 动态规划双指针
// 在上面对动态规划方法的分析中我们得到，如果采取单指针（指向当前列）的策略，必须得使用辅助数组来记录leftHIgh和rightHigh。
// 但是leftHIgh和rightHigh数组的值都是只使用一次的，一直存在数组里有点浪费，我们要想办法用两个变量来存储他们。
// 前面我们知道向右遍历时leftHigh很容易实现单变量存储并更新。但向右遍历时rightHigh的更新是个问题。
// 要想解决向右遍历时rightHigh的更新问题，就引出了双指针：

// -------------------------------------------------------------下面这些没理清，太烧脑了，等下次再刷这道题再好好想想
// 核心思想就是找到一个情况，当这种情况发生时，就由left右移变成right左移。
// 先来看下面的示例推导
// [0,	1,	0,	2,	1,	0,	1,	3,	2,	1,	2,	1]
//	i-1	i  i+1										（这是单指针的移动方式）
//		l  									r		（这是双指针的移动方式）这里有 height[left-1] < height[right+1]，左移使用left指针右移
// =l==     =========right area==================
//													leftHigh=0 < rightHigh=1 , so shortHigh=0 => sum不更新，l右移
//		    l  								r
// =l====       =========right area==============
// 好，当l到了新位置后又该怎么移呢


//				  i2-1	i2  i2+1						（i1右移一步成为i2， 在循环中是同一个变量，这里为了说明方便）
// =====left area=====      =======right area=====
//
// 我们知道rightHigh是right area最大值，那么有 height[i1+1] <= rightHigh
// 当 i 右移一步， left area 向右扩张一步， 其 leftHigh2 = max( leftHigh1, height[i2-1])  (leftHigh1用来代表旧值，2代表新值)
// 显然有 leftHigh1 <= leftHigh2
// 那么！ 一个很巧妙的地方来了！
// 如果 height[i2-1] < height[i1]

//315/315 cases passed (4 ms)
//Your runtime beats 90.82 % of golang submissions
//Your memory usage beats 67.5 % of golang submissions (2.8 MB)
func Sol_1_4(height []int) int {
	var sum, leftHigh, rightHigh, shortHigh int  // sum为装水总量
	left, right := 1, len(height)-2

	for i:=1; i<len(height)-1; i++ {	// i现在只用来控制循环终止，失去指针作用
		// 从左往右更
		if height[left-1] < height[right+1] {
			leftHigh = max(leftHigh, height[left-1]) 	// 计算 leftHigh 数组
			shortHigh = leftHigh						// 这只是为了方便理解，可以去掉shortHigh
			if shortHigh > height[left] {
				sum = sum + shortHigh - height[left]
			}
			left++
		} else {	// 从右往左更
			rightHigh = max(rightHigh, height[right+1])
			shortHigh = rightHigh
			if shortHigh > height[right] {
				sum = sum + shortHigh - height[right]
			}
			right--
		}
	}
	return sum
}

// 栈
// 将接雨水与扩匹配进行类比，每次匹配出一对括号（对应的两堵墙），就能计算两堵墙中间的水
// go原生没有栈容器，但它有个container/list是一个完整的双向链表。这里我用它来实现栈的操作。
// 虽然由于类型转换等等因素肯定开销比较大，但好过每次刷题自己再写一个栈
// 栈空： 链表长度为0 list.Len() == 0
// 压栈： 链表尾部追加数据 list.PushBack(1)
// 获取栈顶元素，但不出栈（也就是peek操作）： 获取尾端节点的值 list.Back().Value.(int)
// 出栈： 先获取链表尾部节点，再删除链表尾部节点 elem := list.Back(); list.Remove(elem)
// 读值： elem.Value.(int)
func Sol_1_5(height []int) int {
	var sum, shortHigh, distance int  // sum为装水总量
	stack := list.New()		// 注意stack用作栈
	var top *list.Element	// 栈顶元素节点， 其内存储数组下标
	current := 0	// 指针
	for current < len(height) {

		// 栈非空，且栈顶元素所指向的高度 < 当前高度
		for stack.Len() != 0 && height[current] > height[stack.Back().Value.(int)] {
			top = stack.Back()		// 记录这个栈顶
			stack.Remove(top)		// 把这个栈顶元素删除

			if stack.Len() == 0 {break}	// 栈空则退出内层循环
			distance = current - stack.Back().Value.(int) - 1	// 两堵墙之间的距离		// 新的栈顶
			//	fmt.Println("distance=", distance)
			shortHigh = int(math.Min(float64(height[stack.Back().Value.(int)]), float64(height[current])))		// 新的栈顶
			sum = sum + distance * (shortHigh - height[top.Value.(int)])
			//	fmt.Println("sum=", sum)
		}
		// 将当前指向的墙的下标压入栈，并将current后移
		stack.PushBack(current)
		current++
		//fmt.Println("stack.Back().value.int=", stack.Back().Value.(int))
	}

	return sum
}

// 在题解区看到Neil的解法，觉得是比较好理解而且高效的解法，实现如下.
// 这个解法将问题进行切分，比较好理解，虽然多了一遍循环，但仍是O(n)时间
// 而且这个方法巧妙的解决了前面rightHigh需要重新计算的问题！！！因为我们用全局最高边生成了新边界！！！
// 315/315 cases passed (4 ms)
//Your runtime beats 90.82 % of golang submissions
//Your memory usage beats 67.5 % of golang submissions (2.8 MB)
func Sol_1_6(height []int) int {

	// 求最大高度的索引
	maxIndex := 0
	for i:=0; i<len(height); i++ {
		if height[maxIndex] < height[i] {
			maxIndex = i
		}
	}

	sum := 0	// 装水总和

	// 我们把 height 求接水拆分为 height[0:maxIndex+1] 和 height[maxIndex:len(height)] 两个子区间求接水。
	// (注意这时go切片slice[m:n]左闭右开，不要误解)

	sideHigh := 0	// 现在指的是左子区间中的“左高”，“右高”一直都是maxIndex，而且shortHigh一定是leftHigh，也就是sideHigh
	for i:=0; i<maxIndex; i++ {
		if sideHigh > height[i] {
			sum = sum + sideHigh - height[i]
		} else {
			sideHigh = height[i]	// 否则更新sideHigh
		}
	}

	sideHigh = 0  // 现在指的是右子区间中的“右高”，“左高”一直都是maxIndex，而且shortHigh一定是righttHigh，也就是sideHigh
	for i:=len(height)-1; i>maxIndex; i-- {
		if sideHigh > height[i] {
			sum = sum + sideHigh - height[i]
		} else {
			sideHigh = height[i]	// 否则更新sideHigh
		}
	}

	return sum
}

```