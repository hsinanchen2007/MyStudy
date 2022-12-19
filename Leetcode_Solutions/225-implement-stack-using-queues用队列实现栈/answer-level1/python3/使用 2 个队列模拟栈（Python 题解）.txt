使用 2 个队列模拟栈。思路是：2 个队列，只保存其中一个队列有数据。插入 push 的时候，就向有数据的那个队列插入。弹出 pop 的时候，先把有数据的那个队列的前面的数据全部 pop 出来插入另一个队列，只留下最后一个数据单独处理。

```
class MyStack:

  def __init__(self):
    """
    Initialize your data structure here.
    """
    self.queue1 = []
    self.queue2 = []

  def push(self, x: int) -> None:
    """
    Push element x onto stack.
    """
    if len(self.queue1) > 0:
      self.queue1.append(x)
    else:
      self.queue2.append(x)

  def pop(self) -> int:
    """
    Removes the element on top of the stack and returns that element.
    """
    queue1 = self.queue1 if len(self.queue1) > 0 else self.queue2
    queue2 = self.queue2 if len(self.queue1) > 0 else self.queue1
    for i in range(len(queue1) - 1):
      queue2.append(queue1.pop(0))
    return queue1.pop(0)

  def top(self) -> int:
    """
    Get the top element.
    """
    queue1 = self.queue1 if len(self.queue1) > 0 else self.queue2
    queue2 = self.queue2 if len(self.queue1) > 0 else self.queue1
    for i in range(len(queue1) - 1):
      queue2.append(queue1.pop(0))
    top = queue1.pop(0)
    queue2.append(top)
    return top

  def empty(self) -> bool:
    """
    Returns whether the stack is empty.
    """
    return len(self.queue1) == 0 and len(self.queue2) == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```
