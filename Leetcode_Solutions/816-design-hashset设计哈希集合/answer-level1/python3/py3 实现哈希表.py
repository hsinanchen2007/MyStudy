很简单，就是把key值通过一个函数映射成位置，在这里我选择了key%maxsize作为哈希函数，其实有其他更好的函数，可以自行百度；
如果发生了哈希冲突，那就进行重哈希（key+1)，值得一提的是：-1代表没有被插入过，这个位置的后面不可能再有值（否则就插到这个位置上了）；而-2代表曾经被插过但又被删除了，它后面是可能有值的，需要继续查找：
```
class MyHashSet:
    def __init__(self):
        self.item=[-1]*8
        self.maxsize=4
        self.leng=0
        self.factor=0.
    def add(self, key: int):
        index=key%self.maxsize
        while(self.item[index] not in [-1,-2]):
            if(self.item[index]==key):
                break
            index=(index+1)%self.maxsize
        if (self.item[index] == key):
            return
        self.item[index]=key
        self.leng+=1
        self.factor=self.leng/self.maxsize
        if(self.factor>=0.8):
            self.rehash()
    def rehash(self):
        old=self.item
        self.item=[-1]*len(old)*2
        self.maxsize*=2
        self.leng=0
        self.factor=0
        for i in old:
            if(i not in [-1,-2]):
                self.add(i)
    def remove(self, key: int) -> None:
        index=key%self.maxsize
        while(self.item[index] is not -1):
            if(self.item[index]==key):
                break
            index=(index+1)%self.maxsize
        if(self.item[index] is not -1):
            self.item[index]=-2
    def contains(self, key: int) -> bool:
        index=key%self.maxsize
        while(self.item[index] is not -1):
            if(self.item[index]==key):
                break
            index=(index+1)%self.maxsize
        if(self.item[index]==-1):
            return False
        else:
            return True
```
