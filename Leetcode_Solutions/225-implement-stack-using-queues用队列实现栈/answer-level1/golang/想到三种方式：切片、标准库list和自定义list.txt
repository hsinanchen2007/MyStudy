### 解题思路
Go标准库里没有队列，可以用数组（切片）或链表来实现：
1. 使用数组切片；push就是append，pop就是调整切片长度，top就是返回最后一个元素
2. 使用标准库container/list包装
3. 自定义list，标准库的list是个双链表且将值定为interface{}类型，这里可以简化为单链表并确定数据类型为int

### 代码
1.使用切片
```golang
type MyStack struct {
    slice []int
}

/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{}
}

/** Push element x onto stack. */
func (s *MyStack) Push(x int)  {
    s.slice = append(s.slice, x)
}

/** Removes the element on top of the stack and returns that element. */
func (s *MyStack) Pop() int {
    if len(s.slice) == 0 {return -1}
    r := s.slice[len(s.slice)-1]
    s.slice = s.slice[:len(s.slice)-1]
    return r
}

/** Get the top element. */
func (s *MyStack) Top() int {
    if len(s.slice) == 0 {return -1}
    return s.slice[len(s.slice)-1]
}

/** Returns whether the stack is empty. */
func (s *MyStack) Empty() bool {
    return len(s.slice) == 0
}
```
2.使用标准库list

```golang
type MyStack struct {
    *list.List
}

/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{list.New()}
}

/** Push element x onto stack. */
func (s *MyStack) Push(x int)  {
    s.PushBack(x)
}

/** Removes the element on top of the stack and returns that element. */
func (s *MyStack) Pop() int {
    if s.Len() == 0 {return -1}
    return s.Remove(s.Back()).(int)
}

/** Get the top element. */
func (s *MyStack) Top() int {
    if s.Len() == 0 {return -1}
    return s.Back().Value.(int)
}

/** Returns whether the stack is empty. */
func (s *MyStack) Empty() bool {
    return s.Len() == 0
}
```
3.自定义list
```
type Node struct {
    Next *Node
    Val int
}
type MyStack struct {
    top *Node
}

/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{}
}

/** Push element x onto stack. */
func (s *MyStack) Push(x int) {
    node := &Node{Next: s.top, Val: x}
    s.top = node
}

/** Removes the element on top of the stack and returns that element. */
func (s *MyStack) Pop() int {
    if s.top == nil {return -1}
    r := s.top.Val
    s.top.Next, s.top = nil, s.top.Next // 这里注意把pop的节点的Next置为nil，防止内存泄露
    return r
}

/** Get the top element. */
func (s *MyStack) Top() int {
    if s.top==nil {return -1}
    return s.top.Val
}

/** Returns whether the stack is empty. */
func (s *MyStack) Empty() bool {
    return s.top == nil
}
```