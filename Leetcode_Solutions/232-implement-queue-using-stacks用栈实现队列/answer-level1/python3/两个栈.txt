```
class MyQueue:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack1 = []
        self.stack2 = []


    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.stack1.append(x)
      
    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        while len(self.stack1) > 1:   # stack1=[1,2,3,4]
            self.stack2.append(self.stack1.pop())  # stack1=[1], stack2=[4,3,2]
        tmp = self.stack1.pop()  # tmp=1,stack1=[]
       
        self.stack1, self.stack2 = self.stack2[::-1], self.stack1   # 交换后stack1=[2,3,4], stack2=[]
        return tmp

    def peek(self) -> int:
        """
        Get the front element.
        """
   
        while len(self.stack1) > 1:  # stack1[1,2,3,4]
            self.stack2.append(self.stack1.pop())  # stack1[1], stack2[4,3,2]
        tmp = self.stack1[-1]  # tmp = 1
        self.stack2.append(self.stack1.pop()) # stack1[], stack2[4,3,2,1]
        self.stack1, self.stack2 = self.stack2[::-1], self.stack1   # 交换后stack1[1,2,3,4], stack2[]
        return tmp

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return len(self.stack1) == 0

# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
![image.png](https://pic.leetcode-cn.com/feb152eb863a854b286d137c1b937eec4e9dd20df1437b24ab7131089745355d-image.png)

```
