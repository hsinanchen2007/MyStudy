```
class CQueue:

    def __init__(self):
        self.nums = []
        self.helper = []        

    def appendTail(self, value: int) -> None:
        self.nums.append(value)

    def deleteHead(self) -> int:
        if not self.nums:
            return -1
        while len(self.nums)>1:
            self.helper.append(self.nums.pop()) 
        delete_num =  self.nums.pop()
        while self.helper:
            self.nums.append(self.helper.pop())
        return delete_num
```
1.nums用来存放数据，helper用来辅助。
2.每次添加数据时，直接添加至nums中。
3.每次删除数据时，先判nums中是否有数据。若没有，return -1。
  若有，（1）第1个数据不动，其他的数据都压入helper中；
        （2）从nums中把第1个数据弹出，并保存；
        （3）再从helper中把数据依次弹出并压入nums中，保持原有的顺序；
        （4）return队首数据。