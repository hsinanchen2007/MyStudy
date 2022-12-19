### 解题思路
此处撰写解题思路

### 代码

```python3
class AnimalShelf:

    def __init__(self):
        self.que = []

    def enqueue(self, animal: List[int]) -> None:
        self.que.insert(0, animal)

    def dequeueAny(self) -> List[int]:
        ret = [-1,-1]
        if self.que:
            ret = self.que.pop()
        return ret

    def dequeueDog(self) -> List[int]:
        i = len(self.que)-1
        ret = [-1, -1]
        while i >= 0:
            if self.que[i][1] == 1:
                ret = self.que[i]
                del self.que[i]
                break
            i -= 1    
        return ret

    def dequeueCat(self) -> List[int]:
        i = len(self.que) - 1
        ret = [-1, -1]
        while i >= 0:
            if self.que[i][1] == 0:
                ret =  self.que[i]
                del self.que[i]
                break
            i -= 1
        return ret

# Your AnimalShelf object will be instantiated and called as such:
# obj = AnimalShelf()
# obj.enqueue(animal)
# param_2 = obj.dequeueAny()
# param_3 = obj.dequeueDog()
# param_4 = obj.dequeueCat()
```