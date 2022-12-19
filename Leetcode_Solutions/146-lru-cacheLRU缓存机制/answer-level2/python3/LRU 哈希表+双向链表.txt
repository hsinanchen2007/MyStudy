### 解题思路
写的很乱 
应该把双向链表封装一下, 基本流程就是下面的
```
int get(int key) {
    if (key 不存在) {
        return -1;
    } else {        
        将数据 (key, val) 提到开头；
        return val;
    }
}

void put(int key, int val) {
    Node x = new Node(key, val);
    if (key 已存在) {
        把旧的数据删除；
        将新节点 x 插入到开头；
    } else {
        if (cache 已满) {
            删除链表的最后一个数据腾位置；
            删除 map 中映射到该数据的键；
        } 
        将新节点 x 插入到开头；
        map 中新建 key 对新节点 x 的映射；
    }
}
```
作者：labuladong
链接：https://leetcode-cn.com/problems/lru-cache/solution/lru-ce-lue-xiang-jie-he-shi-xian-by-labuladong/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

### 代码

```python3
class linkNode:
    def __init__(self, val, key):
        self.next = None
        self.pre = None
        self.val = val
        self.key = key

class LRUCache:
    def __init__(self, capacity: int):
        self.d = {}
        self.capacity = capacity
        self.curlen = 0
        # both.next指向开头, both.pre指向末尾
        self.both = linkNode(-1, -1)

    def get(self, key: int) -> int:
        if key not in self.d:
            return -1
        # 抽取d[key]
        self.d[key].pre.next = self.d[key].next
        self.d[key].next.pre = self.d[key].pre
        # 和first key连
        self.d[key].next = self.both.next
        self.both.next.pre = self.d[key]
        # 和begin连        
        self.d[key].pre = self.both
        self.both.next = self.d[key]

        return self.d[key].val
         
        
    def put(self, key: int, value: int) -> None:
        cur = linkNode(value, key)
        if key in self.d: # 如果这个key已经存在 替换它
            # 和first key连
            cur.next = self.both.next
            self.both.next.pre = cur
            # 和begin连
            cur.pre = self.both
            self.both.next = cur
            # 删除d[key]
            self.d[key].pre.next = self.d[key].next
            self.d[key].next.pre = self.d[key].pre
            self.d[key] = cur
            return
            
        self.d[key] = cur
        self.curlen += 1
        if self.curlen==1:
            self.both.next = self.d[key] # 头部指针
            self.both.pre = self.d[key] # 尾部指针
            self.d[key].pre = self.both
            self.d[key].next = self.both
            return
        # 和first key连
        cur.next = self.both.next
        self.both.next.pre = cur
        # 和begin连
        cur.pre = self.both
        self.both.next = cur

        if self.curlen>self.capacity:
            self.d.pop(self.both.pre.key)
            self.both.pre = self.both.pre.pre
            self.both.pre.next = self.both





# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```