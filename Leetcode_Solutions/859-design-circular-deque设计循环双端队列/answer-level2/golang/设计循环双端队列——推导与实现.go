
内含详细思路，有兴趣的可以看下

![image.png](https://pic.leetcode-cn.com/22316df3adf39c7a356a751637fcd1f7b750c2383d6cf2a0d96f4a2efb955587-image.png)


## 循环双端队列思路与实现

```go
package lt641

// 设计实现双端队列。
//你的实现需要支持以下操作：
//
//    MyCircularDeque(k)：构造函数,双端队列的大小为k。
//    insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true。
//    insertLast()：将一个元素添加到双端队列尾部。如果操作成功返回 true。
//    deleteFront()：从双端队列头部删除一个元素。 如果操作成功返回 true。
//    deleteLast()：从双端队列尾部删除一个元素。如果操作成功返回 true。
//    getFront()：从双端队列头部获得一个元素。如果双端队列为空，返回 -1。
//    getRear()：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1。
//    isEmpty()：检查双端队列是否为空。
//    isFull()：检查双端队列是否满了。

//    所有值的范围为 [1, 1000]
//    操作次数的范围为 [1, 1000]
//    请不要使用内置的双端队列库。

// ---------------------------------------------------------------

// 来回顾下队列。
// 顺序队列（基于数组，每次取数据需要进行数据搬迁，优化是等位置不够了再一次搬迁）、
// 链式队列（容易实现，无限扩展，但不太常用）、
// 循环队列（基于数组，head/tail循环移动，多占用一个数据空间）、
// 阻塞队列（取空队列头部阻塞至有值入队）、
// 并发队列(最简单的就是入队出队操作加锁)

// 队列的应用
// 线程池等资源池，通常有最大数量限制，不适合链式队列
// 银行等业务排队系统

// --------------------------------------------------------------------

// 双端队列就是队头队尾都可以进行出入队操作
// 直接上手干咯，没什么巧的
// 循环队列的难点就在于队满的判定条件。

// 另外题给所有值的范围是[1~1000]这是否要我使用而更小的数据表示类型呢？
// 搞不明白

// 初始队空，f=0=l， 尽管此时一个数据都没有
// fl					// f == l 判空
//[0, 0, 0, 0, 0, 0]	// 为了方便表示，0代表没填充数据
// 插入一个数据， f不变， l后移一位，指向末尾数据的下一位。（如果此时是设计非循环队列，那么 l==n(n为容量)就是判满条件 ）
// f  l
//[1, 0, 0, 0, 0, 0]
// 数据已满 (暂且按照非循环来看，数据满时 l == n (l==6))
// f			     l
//[1, 2, 3, 4, 5, 6]
// 头部取出数据,这时候左边空出了一个位置，l应该挪到那里去
// l  f
//[0, 2, 3, 4, 5, 6]		// 这里是为了演示需要，置0了，其实不用管，移动f/l就行，后面只能取出f~l区间里的数据
// 头部再取一个数据
// l	 f
//[0, 0, 3, 4, 5, 6]		// 这里是为了演示需要，置0了，其实不用管，移动f/l就行，后面只能取出f~l区间里的数据
// 尾部插入一个数据
//    l	 f
//[1, 0, 3, 4, 5, 6]		// 这里是为了演示需要，置0了，其实不用管，移动f/l就行，后面只能取出f~l区间里的数据

// --------------------------------------------------------------------------------
// 前面这个流程存在问题：
// 当l到数组尾部后，l == 7，但是要按循环处理的话， l就得回到0， 那么此时 f==l！导致该条件下不知道是满是空
//
// 为了实现循环队列，留一个位置让 l 指向，不填充数据，以使在队中有数据时 l != f

// 重塑后的流程如下：
// 队列有效容量变成了5

// 初始队空，f=0=l， 此时第一个位置就是 l 的占空位
// fl					// f == l 判空
//[0, 0, 0, 0, 0, 0]	// 为了方便表示，0代表没填充数据
// 插入一个数据， f不变， l后移一位，指向末尾数据的下一位。
// f  l
//[1, 0, 0, 0, 0, 0]
// 数据已满 （1） f=0, l=5=n (n为队列真实容量)
// f			  l
//[1, 2, 3, 4, 5, 0]
// 头部取出数据,这时候左边空出了一个位置，l应该挪到那里去
//    f	 	      l
//[0, 2, 3, 4, 5, 0]		// 这里是为了演示需要，置0了，其实不用管，移动f/l就行，后面只能取出 [f, l) 区间里的数据
// 头部再取一个数据
//  	 f	      l
//[0, 0, 3, 4, 5, 0]
// 尾部插入一个数据. l = (l+1)%n=(5+1)%6=0回到最左边
// l	 f
//[0, 0, 3, 4, 5, 1]
// 尾部再插入一个数据. 队列满（2） f=2, l=1
//    l	 f
//[2, 0, 3, 4, 5, 1]

// 上面有两种队列满的情况。怎么合并在一起来普适性地判断队满呢
// (2)中 l+1 = f
// (1)中 l+1 = 6, f=0, (l+1)%6 = f
// 合并起来就是 (l+1)%6 == f 为队满条件， 6为实际数组容量，5为有效数据容量

// 考虑好了循环队列（单向）后，再来看看循环双端队列。
// 就是加上队尾删除和队头插入的情况。
// 一般情况下很好理解，队尾删除就l前移， 队头插入就f前移。 （除非队已满）
// 但是如果是 f发生了循环左移至数组最末呢
// 其实并不会对队空队满条件产生影响
// 来试着看下这个场景：

// 此时队列还剩一个位置可用，front左移一位，在新的front上插入一个数据
//    f	 	      l
//[0, 2, 3, 4, 5, 0]
// f   	 	      l
//[1, 2, 3, 4, 5, 0]

// 循环右移操作 l = (l + 1) % n
// 循环左移操作 l = (l - 1) % n ? x  这样会使索引越界，因为真正循环的那一次是由 0 -> -1 -> n-1, 所以应该先加一个 n
// l = (n+l-1) % n

// -------------------------------------

// 下面给出我的程序的操作实验结果
//		obj := Constructor(5)
//		param_1 := obj.InsertFront(99)
//		param_2 := obj.InsertLast(88)
//		param_5 := obj.GetFront()
//		param_6 := obj.GetRear()
//		param_3 := obj.DeleteFront()
//		param_4 := obj.DeleteLast()
//		param_7 := obj.IsEmpty()
//		param_8 := obj.IsFull()

// 记录的队列状态为：
// data=[0 0 0 0 0 0], front=0, last=0
//data=[0 0 0 0 0 99], front=5, last=0
//data=[88 0 0 0 0 99], front=5, last=1
//data=[88 0 0 0 0 99], front=5, last=1
//data=[88 0 0 0 0 99], front=5, last=1
//data=[88 0 0 0 0 0], front=0, last=1
//data=[0 0 0 0 0 0], front=0, last=0
//data=[0 0 0 0 0 0], front=0, last=0
//data=[0 0 0 0 0 0], front=0, last=0

// 好了，开始实现循环双端队列

// -------------------------------------------------------------------------------------------------

//51/51 cases passed (20 ms)
//Your runtime beats 61.36 % of golang submissions
//Your memory usage beats 100 % of golang submissions (6.1 MB)
// 占用内存少是因为很多地方没有去用局部变量，而是以计算式传入。
// 运行时间却很一般。稍后分析

// 一个可以提升效率的地方就是可以通过添加容量字段来减少计算容量的运算。

// 奇怪的是，重新提交之后运行效率却击败了百分之九十多....

// 循环双端队列 CircularDoubleEndedQueue
type MyCircularDeque struct {
	data []int	// 数组(切片)存储数据
	// 实际容量为data容量减1，可以在这里记录也可以不记录，我选择不记录
	front int	// “头指针”数组下标
	last int	// “尾指针”数组下标
}

//    MyCircularDeque(k)：构造函数,双端队列的大小为k。
func Constructor(k int) MyCircularDeque {
	return MyCircularDeque{
		// 构造长度容量都为k+1的切片；当然也可以初始化为长度为0，容量为k+1；
		data: make([]int, k+1, k+1),	// 初始值全0
		front:0,
		last:0,
	}
}

//    insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true。
func (this *MyCircularDeque) InsertFront(value int) bool {
	// 检查队列是否已满
	if this.IsFull() {
		return false
	}

	// 插入元素。
	this.front = (len(this.data) + this.front - 1) % len(this.data)	// 先循环左移一位
	this.data[this.front] = value	// 填入数据

	return true
}

//    insertLast()：将一个元素添加到双端队列尾部。如果操作成功返回 true。
func (this *MyCircularDeque) InsertLast(value int) bool {
	// 检查队列是否已满
	if this.IsFull() {
		return false
	}

	// 插入元素
	this.data[this.last] = value	// 填入数据
	this.last = (this.last + 1) % len(this.data)	// 循环右移一位

	return true
}

//    deleteFront()：从双端队列头部删除一个元素。 如果操作成功返回 true。
func (this *MyCircularDeque) DeleteFront() bool {
	// 检查队列是否为空
	if this.IsEmpty() {
		return false
	}

	// 删除头部元素
	//this.data[this.front] = 0	// 置0，这一部完全不是必须，只是为了方便输出调试。可以将这句直接注释
	this.front = (this.front + 1) % len(this.data)	// 循环右移一位

	return true
}

//    deleteLast()：从双端队列尾部删除一个元素。如果操作成功返回 true。
func (this *MyCircularDeque) DeleteLast() bool {
	// 检查队列是否为空
	if this.IsEmpty() {
		return false
	}

	// 删除头部元素
	this.last = (len(this.data) + this.last - 1) % len(this.data)	// 循环左移一位
	//this.data[this.last] = 0	// 置0，这一部完全不是必须，只是为了方便输出调试。可以将这句直接注释

	return true
}

//    getFront()：从双端队列头部获得一个元素。如果双端队列为空，返回 -1。
func (this *MyCircularDeque) GetFront() int {
	// 检查队列是否为空
	if this.IsEmpty() {
		return -1
	}

	// 获取头部元素
	return this.data[this.front]
}

//    getRear()：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1。
func (this *MyCircularDeque) GetRear() int {
	// 检查队列是否为空
	if this.IsEmpty() {
		return -1
	}

	// 获取尾部元素。这里要注意下，last应该循环左移一位得到数据下标
	return this.data[(len(this.data) + this.last - 1) % len(this.data)]
}

//    isEmpty()：检查双端队列是否为空。
func (this *MyCircularDeque) IsEmpty() bool {
	return this.last == this.front
}

//    isFull()：检查双端队列是否满了。
func (this *MyCircularDeque) IsFull() bool {
	return (this.last + 1) % len(this.data) == this.front
}
```

## 链接

- 博客：<https://eiger.me/post/algo/lt641/>
- Github: <https://github.com/azd1997/Leetcode-training/blob/master/lt641/1.go>

