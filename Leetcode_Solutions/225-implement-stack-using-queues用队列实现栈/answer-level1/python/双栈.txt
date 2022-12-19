### 解题思路
此处撰写解题思路

### 代码

```python3
import collections
#https://leetcode-cn.com/problems/implement-stack-using-queues/solution/jie-ti-si-lu-yong-liang-ge-dui-lie-shi-xian-zhan-y/ 
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        import queue as q
        self.q1=q.Queue()
        self.q2=q.Queue()

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q1.put(x)
        

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        # 先将入队的元素放入q2，在取出q1的最后一个数
        while self.q1.qsize() >1:
            self.q2.put(self.q1.get())
        res=self.q1.get()
        # 交换q1和q2 用于下一次操作
        self.q1,self.q2=self.q2,self.q1
        return res


    def top(self) -> int:
        """
        Get the top element.
        """
        #pop 后得到top，但要讲top重新放入到q1
        res=self.pop()
        self.q1.put(res)#现在q1还是那么多元素,注意交换过了
        return res
        
    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return self.q1.empty() and self.q2.empty() # 判断是否为空
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```