### 解题思路
直接模拟就完事了

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue = []

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.queue.append(x)

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        l = len(self.queue)
        while l > 1:
            self.queue.append(self.queue.pop(0))
            l -= 1
        return self.queue.pop(0)

    def top(self) -> int:
        """
        Get the top element.
        """
        l = len(self.queue)
        while l > 1:
            self.queue.append(self.queue.pop(0))
            l -= 1
        ans = self.queue[0]
        self.queue.append(self.queue.pop(0))
        return ans

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        if self.queue:
            return False
        return True
```

```go
type MyStack struct {
    Queue []int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{Queue: []int{}}
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.Queue = append(this.Queue, x)
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    l := len(this.Queue)
    for i := 0; i < l - 1; i++ {
        this.Queue = append(this.Queue[1:], this.Queue[0])
    }
    ans := this.Queue[0]
    this.Queue = this.Queue[1:]
    return ans
}


/** Get the top element. */
func (this *MyStack) Top() int {
    l := len(this.Queue)
    for i := 0; i < l - 1; i++ {
        this.Queue = append(this.Queue[1:], this.Queue[0])
    }
    ans := this.Queue[0]
    this.Queue = append(this.Queue[1:], this.Queue[0])
    return ans
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    if len(this.Queue) == 0 {
        return true
    }
    return false
}
```