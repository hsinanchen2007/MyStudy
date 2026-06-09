import queue 
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.Q_stack = queue.Queue()


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        old_size = self.Q_stack.qsize()
        self.Q_stack.put(x)
        #for i in range(0,old_size):
            #self.Q_stack.put(self.Q_stack.get())



    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        old_size = self.Q_stack.qsize()
        tmp = []
        for i in range(0, old_size):
            tmp.append(self.Q_stack.get())
        for i in range(0, old_size-1):
            self.Q_stack.put(tmp[i])
        return tmp[-1]



    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        old_size = self.Q_stack.qsize()
        tmp = []
        for i in range(0, old_size):
            tmp.append(self.Q_stack.get())
        #tmp.reverse()
        for i in range(0, old_size):
            self.Q_stack.put(tmp[i])
        return tmp[-1]


    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        old_size = self.Q_stack.qsize()
        if old_size == 0:
            return True
        else:
            return False
