用数组有点偷懒，下面写一个代码简洁逻辑易懂的链表设计：
```
class node():
    def __init__(self,x,y=None):
        self.val = x
        self.next = y
        
class MyHashSet:
    def __init__(self):
        self.nums = 1000
        ## 每个哈希桶都是链表，首节点是取值范围外的-1
        self.hset = [node(-1,None) for _ in range(self.nums)] 
        
    def add(self, key: int) -> None: 
        ## 遍历选定的哈希桶，next值等于key就do nothing，否则将链表尾值设为key
        p = bucket = self.hset[key%self.nums]
        try:
            while p.next.val!=key:p = p.next
        except:
            p.next = node(key,None)
            self.hset[key%self.nums] = bucket      
            
    def remove(self, key: int) -> None: 
        ## 遍历选定的哈希桶，next值等于key就将指针指向next的下一个，否则do nothing。
        p = bucket = self.hset[key%self.nums]
        try:
            while p.next.val!=key:p = p.next
            p.next = p.next.next
        except:
            self.hset[key%self.nums] = bucket 

    def contains(self, key: int) -> bool: 
        ## 遍历选定的哈希桶，值不等于key就继续遍历，最后判定是否到链表尾。
        p = self.hset[key%self.nums]
        while p and p.val!=key:p = p.next
        return p != None
```