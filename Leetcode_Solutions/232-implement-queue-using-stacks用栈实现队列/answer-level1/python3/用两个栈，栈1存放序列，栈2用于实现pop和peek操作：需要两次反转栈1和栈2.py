    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack1 = []
        self.stack2 = []

    
    #用于调换两个栈的函数    
    def exStack(self, s1, s2):
        for i in range(len(s1)-1, -1, -1):
            s2.append(s1[i])
            s1.pop()
        
    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.stack1.append(x)

        
    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        self.exStack(self.stack1, self.stack2)
        res = self.stack2[-1]
        self.stack2.pop()
        self.exStack(self.stack2, self.stack1)
        return res

    
    def peek(self) -> int:
        """
        Get the front element.
        """
        self.exStack(self.stack1, self.stack2)
        res = self.stack2[-1]
        self.exStack(self.stack2, self.stack1)
        return res

    
    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        if len(self.stack1) + len(self.stack2) == 0:
            return True
        return False