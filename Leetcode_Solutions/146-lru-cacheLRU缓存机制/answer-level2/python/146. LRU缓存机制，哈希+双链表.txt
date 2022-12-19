### 解题思路
看到题目要我们实现一个可以存储 key-value 形式数据的数据结构，并且可以记录最近访问的 key 值。首先想到的就是用字典来存储 key-value 结构，这样对于查找操作时间复杂度就是 O(1)O(1)。

但是因为字典本身是无序的，所以我们还需要一个类似于队列的结构来记录访问的先后顺序，这个队列需要支持如下几种操作：

在末尾加入一项
去除最前端一项
将队列中某一项移到末尾
首先考虑列表结构。

对于列表加入有 append()，删除有 pop() 操作，这两个都是 O(1)O(1) 的时间复杂度。而对于将队列中某一项移到末尾，因为列表中存储的是哈希表的 key，考虑这样一种情况：

# 操作
cache = LRUCache(4)
cache.put(3, 2)
cache.put(2, 1)
cache.put(1, 1)
# 操作之后队列：
# queue = [3, 2, 1]
此时我们再进行 cache.put(2, 2) 的操作，因为2已经存在在哈希表中，这说明队列中已经存在值为2的元素，那么问题来了，如何在常数时间内把它挑出来移到队尾呢？

答案是不行，所以用列表无法实现常熟时间复杂度。

之后再考虑单链表。

对于单链表，哈希表的结构类似于 {key: ListNode(value)}，即键所对应的是一个节点地址，节点的值是 value。对于链表，遇到上面那种情况时可以在常数的时间内找到对应的节点，但是如果想将它移到尾部则需要从头遍历到该节点才能保证链表不断，对于这种情况需要的时间复杂度也是O(n)O(n)

为了解决移到末尾这个问题，需要使用双链表来记录，结构大概如下图所示：



作者：liye-3
链接：https://leetcode-cn.com/problems/lru-cache/solution/shu-ju-jie-gou-fen-xi-python-ha-xi-shuang-xiang-li/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

### 代码

```python3


# 这里需要定义一个双向链表！！！！！
class ListNode:
    def __init__(self, key=None, value=None):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class LRUCache:

    def __init__(self, capacity: int):
        # 初始化参数
        self.capacity = capacity  # 记录缓存容量
        self.hashmap = {}         # hashmap记录缓存数据键值及数据，value指向双向链表节点

        # 初始化双向链表
        self.head = ListNode()
        self.tail = ListNode()
        # 初始化链表为head<->tail
        self.head.next = self.tail
        self.tail.prev = self.head

    # 创建一个把双向链表中某一个ListNode转移至末尾的函数
    def move_node_to_tail(self, key):
        node = self.hashmap[key]
        # 将该node移植链表末尾
        node.prev.next = node.next
        node.next.prev = node.prev

        node.prev = self.tail.prev
        node.next = self.tail
        self.tail.prev.next = node
        self.tail.prev = node


    def get(self, key: int) -> int:
        if key in self.hashmap:
            # 该key值被访问到，移到双向链表末尾
            self.move_node_to_tail(key)
        
        res = self.hashmap.get(key, -1)   # 注意，此时得到的是双线链表的node值，需用value索引到具体值
        if res == -1:
            return res
        else:
            return res.value



    def put(self, key: int, value: int) -> None:
        if key in self.hashmap:
            # 不需要插入键值，但需要更新键值的数据
            self.hashmap[key].value = value
            self.move_node_to_tail(key)

        else:
            # 需要插入新的键值，判断capacity
            if len(self.hashmap) == self.capacity:
                # 同步去掉hashmap以及双向链表中最开始的元素
                self.hashmap.pop(self.head.next.key)
                self.head.next = self.head.next.next
                self.head.next.prev = self.head


            #将新put的数据同步插入hashmap以及双向链表
            new =  ListNode(key,value)
            self.hashmap[key] = new    # 这里注意，我们的hashmap指向的是一个
            self.tail.prev.next = new
            new.prev = self.tail.prev
            new.next = self.tail
            self.tail.prev = new

            




# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```