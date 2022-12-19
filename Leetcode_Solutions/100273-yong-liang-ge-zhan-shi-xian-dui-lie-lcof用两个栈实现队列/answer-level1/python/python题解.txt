### 解题思路
1. 首先设定两个栈 stack_1 和 stack_2.
2. 在队尾添加元素时,这个不用多说直接在 stack_1 加入元素即可.
3. 在队头删除元素时这个要麻烦一点点,我们首先判断下 stack_2 里面是否有元素,如果有的话我们就直接返回 stack_2 栈顶的元素,因为 stack_2 栈顶的元素也就是最初 stack_1 栈底的元素,也就是队头元素.如果 stack_2 是空的,我们接着需要判断 stack_1 是否为空,如果空说明此时队列里没有元素,我们返回 -1 ,如果 stack_1 不是空的,我们则需要取出 stack_1 栈底的元素,我们需要将 stack_1 的元素导入到 stack_2 中,在返回 stack_2 的顶元素即可.

### 代码

```python
class CQueue(object):

    def __init__(self):
        self.stack_1 = []
        self.stack_2 = []

    def appendTail(self, value):
        """
        :type value: int
        :rtype: None
        """
        self.stack_1.append(value)


    def deleteHead(self):
        """
        :rtype: int
        """
        if self.stack_2:
            return self.stack_2.pop()
        elif not self.stack_1:
            return  -1
        else:
            while self.stack_1:
                self.stack_2.append(self.stack_1.pop())
            return self.stack_2.pop()

            




# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()
```