### 解题思路
采用双向链表以及map，实现O(1)操作的lru缓存，记录一下，应该有用。

### 代码

```python3
class link:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.ahead = None
        self.after = None


class LRUCache:
    def print_link(self, head):
        if not head:
            return
        else:
            print(head.val, '->')
            # if head.after:
            self.print_link(head.after)
    
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.store = {}
        self.head = None
        self.tail = None
        

    def get(self, key: int) -> int:
        if key not in self.store:
            # print('not in store', key)
            return -1
        else:
            tmp = self.store[key]
            if not tmp.after:
                # print(key, ' is the tail of the link')
                return self.store[key].val
            elif not tmp.ahead:
                # print('haha')
                # print(key, ' is head of the link')

                tmp_after = tmp.after
                # print(tmp_after.val)
                tmp_after.ahead = None
                self.head = tmp_after
                self.tail.after = tmp
                tmp.ahead = self.tail
                self.tail = tmp
                tmp.after = None
                
            else :
                # print(key, ' is not the head and the tail')
                tmp_ahead = tmp.ahead
                tmp_after = tmp.after
                tmp_ahead.after = tmp_after
                tmp_after.ahead = tmp_ahead
                tmp.ahead = self.tail
                self.tail.after = tmp
                self.tail = tmp
                self.tail.after = None
            # print(self.capacity, [(k, v.val) for k, v in self.store.items()])
            # self.print_link(self.head)
            return tmp.val
                
        

    def put(self, key: int, value: int) -> None:
        

        if key in self.store:
            tmp = self.store[key]
            if not tmp.after:
                tmp.val = value
            elif not tmp.ahead:
                tmp_after = tmp.after
                tmp_after.ahead = None
                self.head = tmp_after
                tmp.ahead = self.tail
                self.tail.after = tmp
                self.tail = tmp
                tmp.after = None
            else :
                tmp_ahead = tmp.ahead
                tmp_after = tmp.after
                tmp_ahead.after = tmp_after
                tmp_after.ahead = tmp_ahead
                tmp.ahead = self.tail
                self.tail.after = tmp
                self.tail = tmp
                self.tail.after = None
            tmp.val = value
        else:
            tmp = link(key, value)

            if not self.store:
                self.head = tmp
                self.tail = tmp
                self.store[key] = tmp
            else:
                self.tail.after = tmp
                tmp.ahead = self.tail
                self.tail = tmp
                self.store[key] = tmp
            # print('head',self.head.key, self.head.val)
            # print('tail',self.tail.key, self.tail.val)
            
            if len(self.store) > self.capacity:
                # print(len(self.store))
                tmp_head = self.head
                self.head = tmp_head.after
                if tmp_head.after:
                    tmp_head.after.ahead = None
                self.store.pop(tmp_head.key)
            # print('head', self.head.key, self.head.val)
        # print(self.capacity, [(k, v.val) for k, v in self.store.items()])
        # self.print_link(self.head)
      


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```