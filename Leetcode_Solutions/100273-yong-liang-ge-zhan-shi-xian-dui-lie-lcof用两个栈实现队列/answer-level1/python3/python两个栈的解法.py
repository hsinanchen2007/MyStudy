### 解题思路
思路就在代码中

### 代码

```python3
class CQueue:

    def __init__(self):
        self.A=[]
        self.B=[]
        #第一种解法：A直接append
        #如果都为空，返回-1
        #否则A里面的元素都放在B里，B-pop


    def appendTail(self, value: int) -> None:
        self.A.append(value)
        



    def deleteHead(self) -> int:
        if len(self.B)==0 and len(self.A)==0:
            return -1
        if len(self.B)==0:
            while len(self.A)!=0:
                self.B.append(self.A.pop())
            return self.B.pop()
        else:
            return self.B.pop()
            
        
        



# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()
```