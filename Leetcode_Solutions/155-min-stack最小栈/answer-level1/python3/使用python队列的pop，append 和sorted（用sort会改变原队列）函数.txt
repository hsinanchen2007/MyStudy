class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.s=[]

    def push(self, x: int) -> None:
        self.s.append(x)

    def pop(self) -> None:
        if len(self.s):
            self.s.pop()


    def top(self) -> int:
        return self.s[-1]


    def getMin(self) -> int:
        if len(self.s):
            a=sorted(self.s)
        return a[0]