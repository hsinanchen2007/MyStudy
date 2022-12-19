### 解题思路
设置猫狗双队列，出队时做判断即可。
### 代码

```python3
class AnimalShelf:
    from collections import deque
    def __init__(self):
        self.dequecat=deque()   
        self.dequedog=deque()

    def enqueue(self, animal: List[int]) -> None:
        if animal[1]==0:
            self.dequecat.append(animal)
        else:
            self.dequedog.append(animal)

    def dequeueAny(self) -> List[int]:
        if not self.dequecat and not self.dequedog:
            return [-1,-1]
        if not self.dequedog:
            return self.dequecat.popleft()
        if not self.dequecat:
            return self.dequedog.popleft()
        if self.dequedog[0][0]<self.dequecat[0][0]:
            return self.dequedog.popleft()
        return self.dequecat.popleft()

    def dequeueDog(self) -> List[int]:
        if not self.dequedog:
            return [-1,-1]
        return self.dequedog.popleft()

    def dequeueCat(self) -> List[int]:
        if not self.dequecat:
            return [-1,-1]
        return self.dequecat.popleft()



# Your AnimalShelf object will be instantiated and called as such:
# obj = AnimalShelf()
# obj.enqueue(animal)
# param_2 = obj.dequeueAny()
# param_3 = obj.dequeueDog()
# param_4 = obj.dequeueCat()
```