![捕获.PNG](https://pic.leetcode-cn.com/fbe56852401c884ad7396efe4be885c2452af985e1be2e3b0c54b452885b41b1-%E6%8D%95%E8%8E%B7.PNG)

```
class AnimalShelf:

    def __init__(self):
        self.elem = []

    def enqueue(self, animal: List[int]) -> None:
        self.elem.insert(0, animal)

    def dequeueAny(self) -> List[int]:
        ret = [-1,-1]
        if self.elem:
            ret = self.elem.pop()
        return ret

    def dequeueDog(self) -> List[int]:
        i = len(self.elem)-1
        ret = [-1,-1]
        while i>=0:
            if self.elem[i][1] == 1:
                ret = self.elem[i]
                del self.elem[i]
                break
            i -= 1    
        return ret

    def dequeueCat(self) -> List[int]:
        i = len(self.elem)-1
        ret = [-1,-1]
        while i>=0:
            if self.elem[i][1] == 0:
                ret =  self.elem[i]
                del self.elem[i]
                break
            i -= 1
        return ret
```
