class MyCircularDeque:

    def __init__(self, k: int):
        self.k=k
        self.q=[]

    def insertFront(self, value: int) -> bool:
        if len(self.q)<self.k :
            self.q.insert(0,value)
            return True
        else :
            return False
        

    def insertLast(self, value: int) -> bool:
        if len(self.q)<self.k :
            self.q+=[value]
            return True
        else :
            return False

    def deleteFront(self) -> bool:
        if self.q :
            self.q.pop(0)
            return True
        else :
            return False
        

    def deleteLast(self) -> bool:
        return self.q.pop() <= float('inf') if self.q else False
       # 这个纯粹是秀技 看不懂的看上面 一样的
       # 因为主要操作是弹出一个元素 而这个元素肯定比无穷要小 所以等同于"return true"
       # 可能一行写完比较炫酷吧 既完成弹出操作又没有另起一行去返回真
        

    def getFront(self) -> int:
        return self.q[0] if self.q else -1
        

    def getRear(self) -> int:
        return self.q[-1] if self.q else -1
        

    def isEmpty(self) -> bool:
        return len(self.q) == 0

    def isFull(self) -> bool:
        return len(self.q) ==self.k