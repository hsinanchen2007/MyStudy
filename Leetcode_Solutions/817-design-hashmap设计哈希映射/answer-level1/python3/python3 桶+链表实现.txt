### 解题思路
一、getbucket()函数将key映射到桶，这里采用取余法，除数为19997；桶以数组的结构形式存在
二、在每个桶中储存一个链表结构，链表节点使用Node类表示，有key、val和next三个属性
三、对桶进行初始化时，定义一个头节点，设置为Node(None,None)，内部不储存具体值，代表链表的开端，便于之后的增删改查操作
四、首先根据key映射到相应的桶，然后在桶内进行链表的更新、查找、删除即可

### 代码

```python3
class MyHashMap:

    def __init__(self):
        self.bucket=[Node(None,None) for _ in range(19997)]

    def put(self, key: int, value: int) -> None:
        curnode=self.bucket[self.getbucket(key)]
        while curnode.next:
            if curnode.next.key==key:
                curnode.next.val=value
                return 
            curnode=curnode.next
        curnode.next=Node(key,value)
        
    def get(self, key: int) -> int:
        curnode=self.bucket[self.getbucket(key)].next
        while curnode:
            if curnode.key==key:
                return curnode.val
            curnode=curnode.next
        return -1

    def remove(self, key: int) -> None:
        curnode=self.bucket[self.getbucket(key)]
        while curnode.next:
            if curnode.next.key==key:
                curnode.next=curnode.next.next
                break
            curnode=curnode.next

    def getbucket(self,key):
        return key%19997

class Node:
    def __init__(self,key,val):
        self.key=key
        self.val=val
        self.next=None
```