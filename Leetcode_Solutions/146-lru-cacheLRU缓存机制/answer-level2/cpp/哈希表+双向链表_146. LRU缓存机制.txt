### 解题思路
/*
 * LRU 解释 ——
 * 第一步：申明一个LRUCache，长度为2；
 * 第二步：分别向cache里面put(1,1)和put(2,2)，最近使用的是2，所以2在1前面--> 1 2；
 * 第三步：get(1)，使用1，需要将1移到前面--> 1 2；
 * 第四步：put(3,3)，因为2是最近最少使用的，所以将2作废，此时再get(2)就会返回-1--> 1 3；
 * 第五步：继续put(4,4)，同理作废1，get(1)的话就会返回-1--> 3 4；
 * 第六步：get(3)，将3的位置调整到4前面--> 4 3；
 * 第七步：get(4)，继续调整4到3前面--> 3 4。
 *
 * 从上面的步骤可知，在整个LRUCache使用中，需要频繁地调整首尾元素的位置，使用双向链表结构恰好满足。
 *
 * （redis源码中LRU淘汰策略使用模拟链表的方式，因为redis大多是当内存在用，如果在内存中维护链表，
 * 会增加复杂性，且消耗更多的内存。groupcache源码是使用双向链表实现LRU的。）
 *
 * 以下使用哈希表和双向链表实现LRUCache，其中哈希表存储(key, 节点(key, value)在双向链表中的位置position)，
 * 而双向链表存储节点(key, value)。
 * 1> get()函数：如果存在该key，则先将双向链表中原key节点删除，再将该key节点添加到双向链表的末尾，
 *    越最近使用的key越靠近双向链表的末尾。
 * 2> put()函数：
 *    1) 如果存在该key，先将双向链表中原key节点删除，再将该key添加到双向链表的末尾；
 *    2) 如果put之前元素个数已到达容量，则将双向链表第一个元素删除，越是最近最少使用的key越靠近链头。
 *    3) 不存在该key，也未到达容量，直接添加该key到链表的尾部。
 * */

### 代码
```cpp
private:
    // 缓存容量
    int capacity;
    // 存储节点(key, value)的双向链表
    std::list<std::pair<int, int>> cache;
    // 哈希表: key映射到双向链表节点(key, value)在双向链表中的位置
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;

public:
LRUCache(int capacity) {
    // 初始化容量
    this->capacity = capacity;
}

int get(int key) {
    // 哈希表中是否存在该key
    auto iter = map.find(key);

    // 不存在返回-1
    if (iter == map.end()) {
        return -1;
    }

    // 存在
    // 哈希表存储key对应链表节点的位置，kv为链表该位置上的节点
    std::pair<int, int> kv = *map[key];

    // 删除链表该位置的节点
    cache.erase(map[key]);
    // 将该节点添加到链表尾部
    cache.push_back(kv);

    // 更新哈希表中该节点的位置
    map[key] = cache.end();

    // 返回该节点的value值
    return kv.second;
}

void put(int key, int value) {
    // 哈希表中是否存在该key
    auto iter = map.find(key);

    // 如果不存在
    if (iter == map.end()) {
        // 缓存是否已满
        if (cache.size() == capacity) {
            // cache 已满
            // 删除哈希表中链表第一个节点对应的key值
            map.erase(cache.front().first);
            // 删除链表第一个节点
            cache.pop_front();
        }
        // cache 没满
        // 将该节点添加到链表尾部
        cache.emplace_back(key, value);
        // 因为是添加到链表的尾部，所以在链表的位置为cache.end()前面一个位置
        auto lastPos = --cache.end();
        // 更新哈希表中该key节点对应的位置值
        map[key] = lastPos;
    } else {
        // 哈希表中存在该key，删除链表中原key位置所在的节点
        cache.erase(map[key]);
        // 将该节点添加到链表的尾部
        cache.emplace_back(key, value);
        // 更新哈希表中该key节点对的位置值
        auto lastPos = --cache.end();
        map[key] = lastPos;
    }
}
```

### 实现2
/*
 * LRUCache.h && LRUCache.cpp 的第二种实现，
 * 原理相同，时间复杂度O(1)，空间复杂度O(capacity)
 *
 * 使用哈希表存储key和key对应的双向链表节点，这样在删除时能做到O(1)时间
 * */

### 代码
```cpp
private:
    // 链表节点
    struct DListNode {
        int key, val;
        DListNode *prev, *next;
    };

    // 存储key和链表节点的哈希表
    std::unordered_map<int, DListNode *> cache;
    // 链表的头尾哨兵
    DListNode *head, *tail;
    // 缓存当前大小
    int size;
    // 缓存最大容量
    int capacity;

void addNode(LRUCache::DListNode *node) {
    node->prev = tail->prev;
    tail->prev->next = node;

    node->next = tail;
    tail->prev = node;
}

void removeNode(LRUCache::DListNode *node) {
    DListNode *prevNode = node->prev;
    DListNode *nextNode = node->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;
}

void moveToTail(LRUCache::DListNode *node) {
    removeNode(node);
    addNode(node);
}

DListNode *LRUCache::popHead() {
    DListNode *popNode = head->next;
    removeNode(popNode);

    return popNode;
}

LRUCache(int capacity) {
    this->size = 0;
    this->capacity = capacity;

    head = new DListNode();
    tail = new DListNode();

    head->next = tail;
    tail->prev = head;
}

int get(int key) {
    // 在哈希表中查找该key是否存在
    DListNode *node = cache[key];
    // 不存在返回-1
    if (node == nullptr) {
        return -1;
    }

    // 存在则将双向链表中的该节点移到链表尾部
    moveToTail(node);

    // 返回该节点的value值
    return node->val;
}

void put(int key, int value) {
    // 在哈希表中查找该key是否存在
    DListNode *node = cache[key];
    // 如果不存在
    if (node == nullptr) {
        // 定义临时链表节点
        DListNode *newNode = new DListNode();
        newNode->key = key;
        newNode->val = value;

        // 将该节点插入哈希表中
        cache[key] = newNode;
        // 将该节点添加到链表的尾部
        addNode(newNode);
        // 当前缓存大小加1
        ++size;

        // 查看当前大小是否超出缓存容量
        if (size > capacity) {
            // 如果超出，则将链表第一个节点删除
            DListNode *head = popHead();
            cache.erase(head->key);
            --size;
        }
    } else {
        // 如果在链表中存在该节点，更新该节点的value值
        node->val = value;
        // 将该节点移到链表的尾部
        moveToTail(node);
    }
}

```