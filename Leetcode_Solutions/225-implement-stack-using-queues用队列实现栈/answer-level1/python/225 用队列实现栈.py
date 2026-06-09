### 解题思路
用python的列表代表队列
整体思路就是每次来一个新的数时，先把队列之前的数都放入pop_element里面，然后让最新的数进入队列，再让pop_element里面的数重新回队列，其实是一个逆序的过程。
注意：
1、pop_element.append(self.queue1.pop(0))
每次是pop第一个，因为pop出去这个数就没有了，最后会变成空
2、top是返回队列第一个而pop是直接弹出第一个


### 代码

```python
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue1 = []



    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        pop_element = []
        if self.queue1 != []:
            for i in range(len(self.queue1)):
                pop_element.append(self.queue1.pop(0))
            self.queue1.append(x)
            for i,element in enumerate(pop_element):
                self.queue1.append(element)
            
        else:
            self.queue1.append(x)
        return self.queue1
 
        

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        return self.queue1.pop(0)


    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.queue1[0]



    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        if self.queue1 == []:
            return True
        else:
            return False



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```