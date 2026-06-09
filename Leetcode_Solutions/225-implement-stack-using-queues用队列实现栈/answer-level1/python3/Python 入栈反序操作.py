### 解题思路
	1. 创建队列q1
	2. push(x)：将x直接push到q1，除x外所有元素均从队首取出后再push到q1，此时队首为x
	3. pop()：q1首个元素出队
	4. top()：获取q1首个元素
	5. empty()：q1的长度是否为0

### 代码

```python
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q1 = []

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q1.append(x)
        length = len(self.q1)
        for i in range(length - 1):
            temp = self.q1[0]
            del self.q1[0]
            self.q1.append(temp)

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        temp = self.q1[0]
        del self.q1[0]
        return temp

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.q1[0]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.q1) == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()

```