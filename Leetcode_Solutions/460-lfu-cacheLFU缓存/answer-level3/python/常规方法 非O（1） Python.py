### 解题思路
LFU（Least Frequently Used）最近最少使用算法。它是基于“如果一个数据在最近一段时间内使用次数很少，那么在将来一段时间内被使用的可能性也很小”的思路。

　　注意LFU和LRU算法的不同之处，LRU的淘汰规则是基于访问时间，而LFU是基于访问次数的。举个简单的例子：

　　假设缓存大小为3，数据访问序列为set(2,2),set(1,1),get(2),get(1),get(2),set(3,3),set(4,4)，

　　则在set(4,4)时对于LFU算法应该淘汰(3,3)，而LRU应该淘汰(1,1)。

　　那么LFU Cache应该支持的操作为：

　　get(key)：如果Cache中存在该key，则返回对应的value值，否则，返回-1；

　　set(key,value)：如果Cache中存在该key，则重置value值；如果不存在该key，则将该key插入到到Cache中，若Cache已满，则淘汰最少访问的数据。

　　为了能够淘汰最少使用的数据，因此LFU算法最简单的一种设计思路就是 利用一个数组存储 数据项，用hashmap存储每个数据项在数组中对应的位置，然后为每个数据项设计一个访问频次，当数据项被命中时，访问频次自增，在淘汰的时候淘汰访问频次最少的数据。这样一来的话，在插入数据和访问数据的时候都能达到O(1)的时间复杂度，在淘汰数据的时候，通过选择算法得到应该淘汰的数据项在数组中的索引，并将该索引位置的内容替换为新来的数据内容即可，这样的话，淘汰数据的操作时间复杂度为O(n)。

　　另外还有一种实现思路就是利用 小顶堆+hashmap，小顶堆插入、删除操作都能达到O(logn)时间复杂度，因此效率相比第一种实现方法更加高效。

引用地址：[https://www.cnblogs.com/dolphin0520/p/3749259.html](https://www.cnblogs.com/dolphin0520/p/3749259.html)

### 代码

```python3
class Node:
    __slots__ = 'key', 'val', 'cnt'

    def __init__(self, key, val, cnt=0):
        self.key, self.val, self.cnt = key, val, cnt

class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.dic = {}
        self.cnt2node = defaultdict(OrderedDict)
        self.mincnt = 0


    def get(self, key: int) -> int:
        if key not in self.dic:
            return -1
        node = self.dic[key]
        del self.cnt2node[node.cnt][key]

        if not self.cnt2node[node.cnt]:
            del self.cnt2node[node.cnt]
        node.cnt +=1
        self.cnt2node[node.cnt][key] = node

        if not self.cnt2node[self.mincnt]:
            self.mincnt +=1
        return node.val

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0 :
            return
        if key in self.dic:
            self.dic[key].val = value
            self.get(key)
            return
        if len(self.dic) >= self.capacity:
            pop_key,_pop_node = self.cnt2node[self.mincnt].popitem(last=False)
            del self.dic[pop_key]
        
        self.dic[key] = self.cnt2node[1][key] = Node(key,value,1)
        self.mincnt = 1
        


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```