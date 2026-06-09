### 解题思路
###设立两个栈，一个从尾部添加元素，一个完成元素的倒序。
`第一个直接append添加元素`
`第二个栈分为三种情况`
`1.若stack2存在元素，则直接对stack2进行pop返回栈顶元素`
`2.若stack1没有元素，则返回-1`
`3.若stack1存在元素，则将stack1中的元素出栈之后放入stack2中，然后将stack2的元素弹出即为队列的首元素`
### 代码

```python
class CQueue(object):

    def __init__(self):
        #从尾部添加元素
        self.stack1 = []
        #完成元素的倒序
        self.stack2 = []

    def appendTail(self, value):
        """
        :type value: int
        :rtype: None
        """
        self.stack1.append(value)


    def deleteHead(self):
        """
        :rtype: int
        """
        if self.stack2:
            return self.stack2.pop()
        if not self.stack1:
            return -1
        while self.stack1:
            self.stack2.append(self.stack1.pop())
        return self.stack2.pop()



# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()
```