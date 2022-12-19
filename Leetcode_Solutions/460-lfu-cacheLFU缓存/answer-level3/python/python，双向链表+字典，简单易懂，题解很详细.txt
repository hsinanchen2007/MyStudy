### 解题思路
在LRU基础上，本题仍可采用字典+双向链表，以实现快速访问。

##### 基本数据结构：
- 字典，键为`key`，值为`key`对应链表中的节点`node`，即`key:node`
- 双向链表，自定义一个双链表节点`dlNode`类，其中
   - 链表数据为一个列表，包括`[key, value, cnt]`，其中`key`和`value`分别为缓存中`key`和`value`，`cnt`用于记录被访问的次数，默认`cnt = 0`
   - 链表指针包括前指针`pre`和后指针`nxt`，即双向链表
   - 维护链表节点顺序**按照访问次数的降序排列，即访问次数越大越靠前、访问次数相同情况下越"新"越靠前**
   - 进而，缓存已满需删除链表节点时，删除的是尾节点

##### 主要方法逻辑：
- `__init__`：定义容量`self.c = capacity`，初始化字典`self.cache = {}`，初始化双向链表。这里，在双向链表初始化中，为避免处理头、尾节点时的复杂特判，采用链表通用技巧即增加虚拟节点处理，因为是双向链表，所以加虚拟头尾两个节点并首尾相连
    - `self.head = dlNode(1, 1, float('inf'))`#头节点，定义访问次数正无穷
    - `self.tail = dlNode(-1, -1, float('-inf'))`#尾节点，定义访问次数负无穷
    - `self.head.nxt = self.tail` 
    - `self.tail.pre = self.head`
- `_refresh`：辅助刷新位置函数，接收一个节点和其对应**新**访问次数作为参数。更新原则是：
    - 如果节点访问次数小于其前节点的访问次数，说明仍然有序，无需更新
    - 否则，根据`cnt`大小尽可能移动到靠前的位置，即移动到所有不大于其访问次数的节点之前，保证越大越"新"越靠前
- `get`：get操作意味着其访问次数+1，其实现逻辑：
    - 如果缓存容量`self.c <= 0`或目标键值不在缓存字典中，直接返回-1
    - 否则，通过字典找到该节点，通过节点获取访问次数，令访问次数+1后刷新其位置
    - 最后，返回其value值
- `put`：put操作情况略显复杂，包括以下情况：
    - 如果缓存容量`self.c <= 0`，直接返回
    - 否则，区分待添加值是否已在缓存字典中：
        - 如果已在缓存字典中，则仅简单更新访问次数并刷新位置即可（无需考虑缓存容量），需注意的是这里既要更新访问次数`cnt`，**也要更新可能变化的`value`值**
        - 如果不在缓存字典，则加入之前还要考虑缓存容量是否已满：
            - 如果缓存容量已满，则先剔除链表尾部节点（更准确的说是`self.tail`前的那个节点）
            - 加入节点，并前移到尽可能靠前的位置（调用`_refresh()`）

**运行效率一般，权当看个热闹！**

### 代码

```python3
class dlNode:
    def __init__(self, key, val, cnt=0):
        self.val = [key, val, cnt]#键、值、访问次数
        self.pre = None
        self.nxt = None


class LFUCache:
    def __init__(self, capacity: int):
        self.cache = {}#通过key保存链表节点，key:node
        self.c = capacity#字典容量
        self.head = dlNode(1, 1, float('inf'))#头节点，定义访问次数正无穷
        self.tail = dlNode(-1, -1, float('-inf'))#尾节点，定义访问次数负无穷
        self.head.nxt = self.tail 
        self.tail.pre = self.head

    def _refresh(self, node, cnt):##辅助函数，对节点node，以访问次数cnt重新定义其位置
        pNode, nNode = node.pre, node.nxt #当前节点的前后节点
        if cnt < pNode.val[2]:#如果访问次数小于前节点的访问次数，无需更新位置
            return
        pNode.nxt, nNode.pre = nNode, pNode#将前后连起来，跳过node位置
        while cnt >= pNode.val[2]:#前移到尽可能靠前的位置后插入
            pNode = pNode.pre
        nNode = pNode.nxt
        pNode.nxt = nNode.pre = node
        node.pre, node.nxt = pNode, nNode

    def get(self, key: int) -> int:
        if self.c <= 0 or key not in self.cache:#如果容量<=0或者key不在字典中，直接返回-1
            return -1
        node = self.cache[key]#通过字典找到节点
        _, value, cnt = node.val#通过节点得到key，value和cnt
        node.val[2] = cnt+1#访问次数+1
        self._refresh(node, cnt+1)#刷新位置
        return value

    def put(self, key: int, value: int) -> None:
        if self.c <= 0:#缓存容量<=0
            return
        if key in self.cache:#已在字典中，则要更新其value，同时访问次数+1刷新位置
            node = self.cache[key]
            _, _, cnt = node.val
            node.val = [key, value, cnt+1]#更新其值
            self._refresh(node, cnt+1)
        else:
            if len(self.cache) >= self.c: #容量已满，先清除掉尾部元素
                tp, tpp = self.tail.pre, self.tail.pre.pre
                self.cache.pop(tp.val[0]) #从字典剔除尾节点
                tpp.nxt, self.tail.pre = self.tail, tpp #首尾相连，跳过原尾节点
            node = dlNode(key, value)#新建节点，并插入到队尾，再刷新其位置
            node.pre, node.nxt = self.tail.pre, self.tail
            self.tail.pre.nxt, self.tail.pre = node, node
            self.cache[key] = node
            self._refresh(node, 0)
```
最后，欢迎关注个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)