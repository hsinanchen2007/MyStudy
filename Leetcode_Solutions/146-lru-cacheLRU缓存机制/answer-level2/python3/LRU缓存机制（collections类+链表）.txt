两种方法，大神们都解释的差不多了，我就是蹭个题解

第一种：利用第三方库collections，实现有序字典OrderedDict（）



    from collections import OrderedDict
    class LRUCache:
        def __init__(self, capacity: int):
            self.capacity = capacity
            self.lrucache = OrderedDict()

        def get(self, key: int) -> int:
            if key not in self.lrucache:return -1
        
            self.lrucache.move_to_end(key)
            return self.lrucache.get(key)

        def put(self, key: int, value: int) -> None: 
            if key in self.lrucache:
                self.lrucache[key] = value
            else:
                if len(self.lrucache) == self.capacity:
                    #self.lrucache.popitem(last=False)
                    self.lrucache.popitem(0)
                self.lrucache[key] = value
            self.lrucache.move_to_end(key)
            '''
            if key in self.lrucache:
                self.lrucache.move_to_end(key)
            self.lrucache[key] = value
            if len(self.lrucache) > self.capacity:
                self.lrucache.popitem(0)
            '''
        

第二种：双向链表，直接看代码吧，和大神们区别不大，很好理解的


    #双向链表
    class ListNode:
        def __init__(self,key=None,value=None):
            self.key = key
            self.value = value
            self.next=None
            self.prev=None
        
    class LRUCache:
        def __init__(self, capacity: int):
            self.capacity = capacity
            self.hashmap = {}
            #建立头尾节点
            self.head = ListNode()
            self.tail = ListNode()
            #初始化链表
            self.head.next = self.tail
            self.tail.prev = self.head
            
            
        def move_to_tail(self,key):
            node = self.hashmap[key]
            
            #将node节点取出来
            node.prev.next = node.next
            node.next.prev = node.prev
            
            #移到最后
            node.prev = self.tail.prev
            node.next = self.tail
            self.tail.prev.next = node
            self.tail.prev = node
            
            
            
        def get(self, key: int) -> int:
            if key not in self.hashmap:return -1
            #key在hashmap中，移动到最后，成为最新访问的节点
            self.move_to_tail(key)
            return self.hashmap[key].value
        
        def put(self, key: int, value: int) -> None: 
            if key in self.hashmap:
                self.move_to_tail(key)
                #更新hashmap中node的值
                self.hashmap[key].value=value
            else:
                if len(self.hashmap)==self.capacity:
                    #根据lru策略，删除最近最少使用的key-value,删除对应hashmap项
                    self.hashmap.pop(self.head.next.key)
                    #去掉第一个节点（head.next）
                    self.head.next = self.head.next.next
                    self.head.next.prev = self.head
                
                #构建新节点new并将其赋值给hashmap[key]
                new = ListNode(key,value)
                self.hashmap[key] = new
                
                #new节点移到最后
                new.prev = self.tail.prev
                new.next = self.tail
                self.tail.prev.next = new
                self.tail.prev = new
         
        