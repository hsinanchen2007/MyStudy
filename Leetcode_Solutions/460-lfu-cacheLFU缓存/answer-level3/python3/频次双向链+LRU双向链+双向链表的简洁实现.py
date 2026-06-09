# ## 解法一：双双向链表
# 在懂得LRU的O(1)时间复杂度实现后，本题并不难，因此不再赘述LRU的实现。


# 首先是频次双向链表，每个频次链表节点中串一个LRU双向链表。其实这种实现下没有第二个附带哈希的解法简单，不过挺锻炼代码实现能力的。😀
# 主要的难点在于双向链表的修改，细节很多，一不小心容易写错。附代码：



# ```
class Node:
    def __init__(self, val):
        self.val = val
        self.next = None
        self.prev = None

    def remove_from_origin_list(self):
        """
        将当前节点从原链表抽出，自身仍保留前后指向关系
        """
        if self.prev is None:
            raise Exception('Delete Error. No prev Node')
        self.prev.next = self.next
        if self.next:
            self.next.prev = self.prev

    def insert_next(self, node):
        if node is None:
            raise Exception('Insert Error. node is None')

        nxt = self.next
        node.next = nxt
        node.prev = self
        self.next = node
        if nxt:
            nxt.prev = node
        
    def __str__(self):
        s = ''
        s += str(self.val) + '->'
        if self.next:
            s += str(self.next)
        return s


class CountNode(Node):
    def __init__(self, *args, **kwags):
        super().__init__(*args, **kwags)
        self.lru_head = Node(0)  # 空头结点, lru 头为最新访问过的节点
        self.lru_tail = None  # 指向尾节点, 最近最少使用的节点
        self.nodes = 0


    def insert_lru(self, lru_node):
        if self.nodes == 0:
            self.lru_tail = lru_node

        self.nodes += 1
        self.lru_head.insert_next(lru_node)
        
    
    def remove_lru(self, lru_node):
        if self.nodes <= 0:
            raise Exception('Count Node Error. Nodes count must > 0')
     
        self.nodes -= 1
        lru_node.remove_from_origin_list()

        if lru_node == self.lru_tail:
            if lru_node.prev != self.lru_head:
                self.lru_tail = lru_node.prev
            else:
                self.lru_tail = None
    

    def pop_lru(self):
        """
        pop尾节点，返回剩余lru节点个数，如果个数为0，当前count节点需要被回收
        :return: pop的lru节点
        """
        lru_node = self.lru_tail
        self.remove_lru(lru_node)
        
        return lru_node
            

    
    def add_count(self, lru_node):
        """
        lru_node必须是count_node中的lru节点, 由LFUCache控制
        :return: lru_node处于的新count_node
        """
        # 直接将lru节点转移到下一个count节点
        if self.next and self.next.val == self.val + 1: 
            self.remove_lru(lru_node)
            self.next.insert_lru(lru_node)
            if self.nodes == 0:
                self.remove_from_origin_list()
            return self.next
      
        # 自己升级为下一个节点
        if self.nodes == 1:
            self.val += 1
            return self
        # 分裂出一个新节点
        else:
            # 分离lru节点
            self.remove_lru(lru_node)
            if self.nodes == 0:
                self.remove_from_origin_list()
            # lru节点插入新频次节点
            new_node = CountNode(self.val + 1)
            new_node.insert_lru(lru_node)
            # 将新节点插入频次链中
            self.insert_next(new_node)
            return new_node

    def __str__(self):
        s = ''
        s += str(self.lru_head) + '->\n'
        s += str(self.lru_tail) + '  nodes:' + str(self.nodes) + ' val: '+str(self.val) + '\n'
        if self.next:
            s += str(self.next)
        return s
        


def debug(func):
    def wrapper(*args, **kwags):
        print('<', func.__name__, '>', str(args), str(kwags))
        res =  func(*args, **kwags)
        print('result:', res)
        return res
    return wrapper


class LFUCache:

    def __init__(self, capacity: int):
        # 频次双向链 + 内部lru双向链
        self.cache = {}
        self.node_map = {} # 存储key对应的lru节点和频次节点
        self.count_nodes = CountNode(0)  # 频次双向链表
        self.size = 0
        self.cap = capacity
        # leetcode 测试用例中会有cap=0的情况，不能直接抛异常，但生产环境中应直接抛异常
        # if self.cap <= 0:
        #     raise Exception('Capacity must greater than 0')

    
    # @debug
    def get(self, key: int) -> int:
        if key in self.cache:
            lru_node, count_node = self.node_map[key]
            new_count_node = count_node.add_count(lru_node)
            self.node_map[lru_node.val] = [lru_node, new_count_node]
            # print(self.count_nodes.next)

            return self.cache[key]
        else:
            return -1

    # @debug
    def put(self, key: int, value: int) -> None:
        # 键已存在则替换并添加访问频次
        if key in self.cache:
            self.get(key)
            self.cache[key] = value
            return

        if self.size == self.cap:
            if self.cap == 0:
                return

            self.size -= 1
            pop_node = self.count_nodes.next.pop_lru()
            # print('pop, ', pop_node.val)
            self.node_map.pop(pop_node.val)
            self.cache.pop(pop_node.val)
            if self.count_nodes.next.nodes == 0:
                self.count_nodes.next.remove_from_origin_list()
            
        self.size += 1
        self.cache[key] = value
        
        lru_node = Node(key)   

        if self.count_nodes.next and self.count_nodes.next.val == 1:
            self.count_nodes.next.insert_lru(lru_node)
            self.node_map[key] = [lru_node, self.count_nodes.next]
        else:
            new_node = CountNode(1)
            new_node.insert_lru(lru_node)
            self.count_nodes.insert_next(new_node)
            self.node_map[key] = [lru_node, new_node]

        # print('cache', self.cache)
        # print(self.count_nodes.next)
# ```



# ## 解法二：哈希存储频次，每个频次节点包含lru双向链表
# 相对简单，只需存储最小频次，即可找到在哈希中找到最小频次的lru双向链表并pop节点。