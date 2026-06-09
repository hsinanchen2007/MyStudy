```py
class MyStack(object):  #  镜像题目 232 225
    # 用队列来是实现　栈
    #　比栈实现实现队列　简单很多。　
    #　其实就是用　列表来实现　栈
    # 只能在最后侧进行操作的队列/列表　其实就是　栈

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._queue=[]  # 创建列表


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        # 将队列的入口 作为栈的底部。 出口作为栈的顶部
        #　这样　在队列中右侧（出口）添加元素，就相当如在栈顶　添加元素
        self._queue.append(x)  # 列表后端添加元素


    def pop(self):  # 弹出　栈顶的元素就是将队列右侧的东西拿出
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        return self._queue.pop(-1)  # 弹出列表的最后一个元素


    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self._queue[-1]  # 访问列表的 最后一个元素


    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        # return not bool(self._queue)
        return not len(self._queue)  # 非零长度的 就是 empty
 
```
