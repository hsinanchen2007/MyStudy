### 解题思路
1. BST, 时间复杂度$O(lgN)$, 空间复杂度$O(N)$
2. HashMap

### 代码

```c++ []
typedef struct _Node{
    int freq = 0; // 缓存块使用的频率    
    int time = 0; // 最近使用该缓存的时间
    int key;  // 缓存的键
    int value;// 缓存的值
    _Node(int freq, int time, int key, int value):freq(freq), time(time), key(key), value(value){}
    bool operator< (const _Node& node) const{
        return freq == node.freq? time<node.time : freq<node.freq;
    }
}Node;

class LFUCache {
public:
    // 使用平衡二叉树求解
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->time = 0; // 当前系统时间
        REC.clear();
        S.clear();
    }
    
    int get(int key) {
        if(capacity == 0) return -1;
        auto it = REC.find(key);
        if(it == REC.end())
            return -1;
        else{
            Node node = it->second;
            // 更新缓存的freq和time信息后重新插入
            S.erase(node);
            node.freq++;
            node.time = ++time; // 更新为当前系统时间
            S.insert(node);
            it->second = node;
            return node.value;
        }
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        auto it = REC.begin();
        it = REC.find(key);
        // 如果是新的key
        if(it == REC.end()){
            // 如果达到存储容量上限, 删除BST最左边缓存块
            if(REC.size() == capacity){
                REC.erase(S.begin()->key);
                S.erase(S.begin());
            }
            // 插入当前缓存块
            Node node = Node(1, ++time, key, value);
            S.insert(node);
            REC.insert(make_pair(key, node));
        }
        else{
            Node node = it->second;
            S.erase(node);
            node.time = ++time;
            node.freq++;
            node.value = value;
            S.insert(node);
            it->second = node;
        }
    }

private:
    int capacity;
    int time;
    unordered_map<int, Node> REC; // 缓存表, 存储<key-缓存块>
    set<Node> S; // 缓存存储, 底层实现为BST
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
```java []
class Node{
    int freq=1; //缓存块的使用频率
    int key;    
    int value;
    Node(int key, int value){
        this.key = key;
        this.value = value;
        this.freq = 1;
    }
}

class LFUCache {

    public LFUCache(int capacity) {
        // 哈希表+双向链表
        this.capacity = capacity;
        this.minFreq = 0;
        this.size = 0;
        this.REC = new HashMap<>(capacity);
        this.FREQ = new HashMap<>();
    }
    
    public int get(int key) {
        if(capacity == 0) return -1;
        if(!REC.containsKey(key)) return -1;
        Node node = REC.get(key);
        incFreq(node);
        return node.value;
    }
    
    public void put(int key, int value) {
        if(capacity == 0) return;
        if(!REC.containsKey(key)){
            if(size == capacity){
                // 删除LFU节点
                Node rmNode = remove();
                // 更新缓存表
                REC.remove(rmNode.key);
                size--;
            }
            // 添加节点
            Node node = new Node(key, value);
            // 更新缓存表
            REC.put(key, node);
            add(node);
            size++;
        }
        else{
            Node node = REC.get(key);
            node.value = value;
            incFreq(node);
        }
    }

    private void incFreq(Node node){
        int freq = node.freq;
        LinkedHashSet<Node> fset = FREQ.get(freq);
        // 从当前频率集合中删除该缓存块
        fset.remove(node);
        if(freq == minFreq && fset.size()==0) minFreq = freq+1;
        // 更新频率后重新插入集合
        node.freq++;
        if(FREQ.containsKey(freq+1))
            FREQ.get(freq+1).add(node);
        else{
            FREQ.put(freq+1, new LinkedHashSet<Node>());
            FREQ.get(freq+1).add(node);
        }
        

    }

    // 添加缓存块
    private void add(Node node){
        // 新加入的缓存块使用频率为1
        if(!FREQ.containsKey(1)){
            FREQ.put(1, new LinkedHashSet<Node>());
            FREQ.get(1).add(node);
        }
        else{
            FREQ.get(1).add(node);
        }
        minFreq = 1;
    }

    // 删除LFU缓存块并返回
    private Node remove(){
        LinkedHashSet<Node> mset = FREQ.get(minFreq);
        Node rmNode = mset.iterator().next();
        mset.remove(rmNode);
        return rmNode;
    }

    private HashMap<Integer, Node> REC; // 存储<key-缓存块>
    private HashMap<Integer, LinkedHashSet<Node>> FREQ; // 存储<缓存使用频率-双向链表集合>
    private int capacity; // 当前缓存的最大容量
    private int minFreq;  // 使用频率最小的缓存块的使用次数
    private int size;     // 当前缓存的大小
}
```
```python []
# 双向链表<参照题解实现>
class Node:
    def __init__(self, key, value, pre=None, nex=None, freq=0):
        self.key = key
        self.value = value
        self.pre = pre
        self.nex = nex
        self.freq = freq

    # 在double linked list中插入节点
    def insert(self, nex):
        nex.pre = self
        nex.nex = self.nex
        self.nex.pre = nex
        self.nex = nex

def initList():
    head, tail = Node(-1, -1), Node(-1, -1)
    head.nex = tail
    tail.pre = head
    return (head, tail)


class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.size = 0
        self.minFreq = 0
        # 存储<缓存块使用频率, 缓存块集合(双向链表存储)>
        self.FREQ = collections.defaultdict(initList)
        # 缓存状态表, 存储<key, 缓存块>
        self.REC = dict()
        

    def get(self, key: int) -> int:
        if self.capacity == 0: return -1
        if key not in self.REC: return -1
        node = self.REC[key]
        self.incNode(node)
        return node.value


    def put(self, key: int, value: int) -> None:
        if self.capacity != 0:
            if key in self.REC:
                node = self.REC[key]
                node.value = value
            else:
                node = Node(key, value)
                self.REC[key] = node
                self.size += 1
            if self.size > self.capacity:
                self.size -= 1
                rmKey = self.removeNode(self.FREQ[self.minFreq][0].nex)
                self.REC.pop(rmKey)
            self.incNode(node)
        
    
    # 添加节点
    def incNode(self, node):
        node.freq+=1
        # 将缓存块从原始频率集合中删除, 添加到新频率集合中(尾插法)
        self.removeNode(node)
        self.FREQ[node.freq][-1].pre.insert(node)
        if node.freq == 1: # 如果是添加新插入的节点
            self.minFreq = 1
        elif self.minFreq == node.freq-1:
            head, tail = self.FREQ[node.freq-1]
            if head.nex is tail:
                self.minFreq = node.freq

    # 删除节点
    def removeNode(self, node):
        if node.pre:
            node.pre.nex = node.nex
            node.nex.pre = node.pre
            # 如果当前频率下链表只剩下head和tail时删除该频率下的双向链表
            if node.pre is self.FREQ[node.freq][0] and node.nex is self.FREQ[node.freq][-1]:
                self.FREQ.pop(node.freq)
        return node.key

```