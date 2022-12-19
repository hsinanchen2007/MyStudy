
基于数组构建栈，min变量记录最小值。pop操作有可能需要遍历更新min，其他情况都O(1), 击败90+%

```go
package lt155

import "math"

//设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
//
//push(x) -- 将元素 x 推入栈中。
//pop() -- 删除栈顶的元素。
//top() -- 获取栈顶元素。
//getMin() -- 检索栈中的最小元素。
//示例:
//
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> 返回 -3.
//minStack.pop();
//minStack.top();      --> 返回 0.
//minStack.getMin();   --> 返回 -2.
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/min-stack
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 思考：
// 太简单了，第一想法
// 无论是基于链表还是数组，都只需要加一个min变量记录最小值。只有当pop操作时才有可能需要O(n)的时间复杂度。
// 也可以空间换时间，用一个辅助链表存储排好序的

// 看了下题解，还有两种思路：
// 1. 使用一个同步增长的辅助栈，记录当前比较的最小值。比如主栈压入 1， 辅助栈压入当前最小值1； 主栈压入2，和辅助栈栈顶比较下，发现最小值还是1，辅助栈不变;主栈再压入1，比主栈顶小
// 不大于辅助栈顶，所以辅助栈再压一个1. 这样保证了任何时候三个操作时间复杂度都是1.
// 2. 另外一个思路是：使用一个变量记录min值，栈中存储 v = x - min。x为真正的值。通过推断 x 与栈顶 v+min 的大小关系可以决定是否更新min。
// pop时同样根据大小关系推断min需不需要更新。这个思路挺好的。缺点是当特殊情况下 min为整型最小值附近的话，x-min就会溢出。为了避免这个问题，只能使用更长的数据表示类型
// 这需要占用更多内存以及类型转换的时间。

// 因为这题重在思路，直到有哪些技巧就行，我就只实现自己的基于数组和变量构建最小栈

// 因为太容易想到，我直接在leetcode上提交然后把代码拷贝过来。

type MinStack struct {
	slice []int
	min int
}


/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{
		slice: make([]int, 0),
		min: math.MaxInt64,       // 假设是64位系统，初始值为整型最大值
	}
}


func (this *MinStack) Push(x int)  {
	this.slice = append(this.slice, x)
	if x < this.min {this.min = x}
}


func (this *MinStack) Pop()  {
	switch len(this.slice) {
	case 0:
		return
	case 1:
		this.min = math.MaxInt64
	case 2:
		this.min = this.slice[0]
	default:    // 长度>2时
		if this.slice[len(this.slice)-1] == this.min {
			// 重新计算最小值(尽管前面也有可能有最小值，但还是重新计算为妥)
			min := math.MaxInt64
			for i:=0; i<len(this.slice)-1; i++ {
				if this.slice[i] < min {min = this.slice[i]}
			}
			this.min = min
		}
		// 否则就是 > , 但是大于不用更新min
	}

	this.slice = this.slice[:len(this.slice)-1]
}


func (this *MinStack) Top() int {
	if len(this.slice) == 0 {return math.MaxInt64}      // 避免0的歧义
	return this.slice[len(this.slice)-1]
}


func (this *MinStack) GetMin() int {
	if len(this.slice) == 0 {return math.MaxInt64}      // 避免0的歧义
	return this.min
}


/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
```