提交通过才看到题解里清一色用List实现的链表，我就来个不一样的，字典实现！
还是很简单的，双链表只需要将字典的key设置为`(pre,next)`样式的元组就行了！
```
class MyLinkedList:

    def __init__(self):
        self.ll = dict()

    def get(self, index: int) -> int:
        return self.ll.get(index,-1)

    def addAtHead(self, val: int) -> None:
        self.ll = {k+1:v for k,v in self.ll.items()}
        self.ll.update({0:val})

    def addAtTail(self, val: int) -> None:
        self.ll.update({max(self.ll.keys())+1:val})

    def addAtIndex(self, index: int, val: int) -> None:
        self.ll = {k+1 if k >= index else k:v for k,v in self.ll.items()}
        
        if 0<=index<=len(self.ll.keys()): self.ll.update({index:val})
            
        elif index<0: return self.addAtHead(val)

    def deleteAtIndex(self, index: int) -> None:
        if index in self.ll.keys():
            self.ll.pop(index)
            self.ll = {k-1 if k >= index else k:v for k,v in self.ll.items()}
```
效率还是蛮低的：
执行用时 :568 ms, 在所有 Python3 提交中击败了14.25%的用户
内存消耗 :14.3 MB, 在所有 Python3 提交中击败了5.21%的用户