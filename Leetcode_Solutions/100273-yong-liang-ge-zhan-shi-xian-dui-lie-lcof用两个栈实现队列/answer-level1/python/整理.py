### 解题思路
重点就是，栈是先进后出，队列是先进先出。
栈a的元素，移动到栈b中，就相当于把元素旋转180度，即元素A在栈a中是第一个元素，在栈b中是最后一个元素；在栈b中删除，相当于在整个队列元素A第一个进，再第一个出，实现队列的操作

### 代码

```python3
class CQueue:

    def __init__(self):
        self.stack_a = []
        self.stack_b = []

    def appendTail(self, value: int) -> None:
        self.stack_a.append(value)
        


    def deleteHead(self) -> int:
        if self.stack_b:
            return self.stack_b.pop()
        elif len(self.stack_a) == 0: 
            return -1
        else:
            while self.stack_a:
                # 将a中的元素放入栈b
                self.stack_b.append(self.stack_a.pop())
            return self.stack_b.pop()
            

# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()
```