# 栈实现
通过构造一个栈，后进先出的特性，

1. 把输入的nums数组放入一个新构造的栈中，

2. 然后把nums数组的后k个数依次Pop出来，并拼接到输出数组output的前面

3. 把nums数组后k个数之前的数字，依次添加到输出数组中

4. 把输出数组赋值给nums数组

```go
// 数组items，数组大小len(nums)
type ArrayQueue struct {
	queue []int
	cap   int
	tail  int
}

func NewArrayQueue(n int) *ArrayQueue {
	return &ArrayQueue{make([]int, n), n, 0}
}

func (self *ArrayQueue) EnQueue(v int) bool {
	if self.tail == self.cap {
		return false
	}
	self.queue[self.tail] = v
	self.tail++
	return true
}
func (self *ArrayQueue) DeQueue() int {
	v := self.queue[self.tail-1]
	self.tail--
	return v
}

func rotate(nums []int, k int) {
	k %= len(nums)
	output := make([]int, len(nums))
	q := NewArrayQueue(len(nums))
	// 使用数组nums构造队列
	for i := range nums {
		q.EnQueue(nums[i])
	}
	// 截取nums数组的后k个
	for i := k - 1; i >= 0; i-- {
		output[i] = q.DeQueue()
	}
	// 拼接到nums数组的前面
	for i := 0; i < len(nums)-k; i++ {
		output[i+k] = nums[i]
	}
    nums = append(nums[:0], output...)
}
```

## 优化

```go
func rotate(nums []int, k int) {
    stack := []int{}
    
    res := make([]int, len(nums))
    k %= len(nums)

    //1. 把输入的nums数组放入一个新构造的栈中，
    for _, n := range nums {
        stack = append(stack, n)
    }
    //2. 然后把nums数组的后k个数依次Pop出来，并拼接到输出数组output的前面
    for i := k - 1; i >= 0; i-- {
        res[i] = stack[len(stack)-1]
        stack = stack[:len(stack)-1]
    }
    //3. 把nums数组后k个数之前的数字，依次添加到输出数组中
    for i := 0; i < len(nums)-k; i++ {
        res[i+k] = nums[i]
    }
    //4. 把输出数组赋值给nums数组
    nums = append(nums[:0], res...)
}
```