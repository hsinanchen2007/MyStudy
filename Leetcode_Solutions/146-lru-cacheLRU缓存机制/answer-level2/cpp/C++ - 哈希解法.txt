### 解题思路
两种思路：
第一种O(n)的链表。很简单。  
第二种：
O(1)的哈希表，比较难写对。如果没有OJ系统的测试用例，我是不可能完全写对这玩意的。  
这里我使用开放链址法解决哈希冲突。

### 代码
O(1)的哈希表实现
```cpp
//执行用时 :88 ms, 在所有 C++ 提交中击败了99.83% 的用户
//内存消耗 :38.4 MB, 在所有 C++ 提交中击败了67.41%的用户
class LRUCache {
private:
    typedef struct _node {
        int key, value;
        struct _node *lru_next, *lru_prev;  // 最近最久未使用的队列
        struct _node *hash_next, *hash_prev; // 哈希表开放链址法的队列
        _node (
            int k, int v,
            struct _node *lruNext = nullptr, struct _node *lruPrev = nullptr,
            struct _node *hashNext = nullptr, struct _node *hashPrev = nullptr
            )
            : key(k), value(v), lru_next(lruNext), lru_prev(lruPrev), hash_next(hashNext), hash_prev(hashPrev) {}
    } _node;

    _node *_head, *_tail;

    int _size, _capacity; // 注：_size 由_lru相关函数进行维护

    vector<_node*> _cache;

public:
    LRUCache(int capacity) : _capacity(capacity), _size(0), _head(nullptr), _tail(nullptr) {
        // init dummy head for _cache
        _cache.resize(_capacity);
        for (int i = 0; i < _capacity; ++i) {
            _node *dummy_node = new _node(-1, -1);
            _cache[i] = dummy_node;
        }
    }
    
    int get(int key) {
        hash<int> int_hash;
        int idx = int_hash(key) % _capacity;

        _node *cur = nullptr;
        if ((cur = _hash_list_find(key, idx)) != nullptr) {
            if (cur != _head) {
                _lru_list_lazy_erase(cur);
                _lru_list_push_front(cur);
            }
            //_lru_traverse_debug();
            return cur->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        hash<int> int_hash;
        int idx = int_hash(key) % _capacity;

        // 0. 如果 _size == 0，则lru队列仍未被初始化，则要初始化它。（能不能在构造函数中完成？）
        if (_size == 0) {
            _lru_list_init(key, value);
            _hash_list_push_front(_head, idx);
            return;
        }

        _node *cur = nullptr;
        // 1. 判断key是否在_cache中存在，如果存在，则：放置到lru队列的队首，更新value值，结束该函数
        if ((cur = _hash_list_find(key, idx)) != nullptr) {
            _lru_list_lazy_erase(cur);
            _lru_list_push_front(cur);
            cur->value = value;
            return;
        }

        // 2. 如果不存在，且lru队列满了，则删除队尾元素
        if (_size == _capacity) {
            cur = _lru_list_pop_back();
            _hash_list_delete_node(cur);
        }

        // 3. 添加新的元素
        _node *node = new _node(key, value);
        _lru_list_push_front(node);
        _hash_list_push_front(node, idx);
    }

private:

    // 前插法插入元素
    void _hash_list_push_front(_node*& cur, int idx) {
        cur->hash_next = _cache[idx]->hash_next;
        cur->hash_prev = _cache[idx];
        if (_cache[idx]->hash_next != nullptr) {
            _cache[idx]->hash_next->hash_prev = cur;
        }
        _cache[idx]->hash_next = cur;
    }

    _node* _hash_list_find(int key, int idx) {
        for (_node *cur = _cache[idx]->hash_next; cur != nullptr; cur = cur->hash_next) {
            if (cur->key == key) {
                return cur;
            }
        }
        return nullptr;
    }

    void _hash_list_delete_node(_node* cur) {
        cur->hash_prev->hash_next = cur->hash_next;
        if (cur->hash_next != nullptr) {
            cur->hash_next->hash_prev = cur->hash_prev;
        }
        if (cur == _head) {
            _head = cur->lru_next;
        }
        if (cur == _tail) {
            _tail = cur->lru_prev;
        }
        delete cur;
    }

    void _lru_list_init(int key, int value) {
        _node *cur = new _node(key, value);
        _head = _tail = cur;
        ++_size;
    }

    void _lru_list_lazy_erase(_node*& node) {
        if (node->lru_prev != nullptr) {
            node->lru_prev->lru_next = node->lru_next;
        }
        if (node->lru_next != nullptr) {
            node->lru_next->lru_prev = node->lru_prev;
        }
        if (node == _head) {
            _head = node->lru_next;
        }
        if (node == _tail) {
            _tail = node->lru_prev;
        }
        node->lru_prev = nullptr;
        node->lru_next = nullptr;
        --_size;
    }

    void _lru_list_push_front(_node*& node) {
        node->lru_next = _head;
        node->lru_prev = nullptr;
        if (_head != nullptr) {
            _head->lru_prev = node;
        }
        _head = node;
        if (_size == 0) {
            _tail = node;
        }
        ++_size;
    }

    _node* _lru_list_pop_back() {
        _node *cur = _tail;
        _tail = _tail->lru_prev;
        if (_tail != nullptr) {
            _tail->lru_next = nullptr;
        }
        --_size;
        return cur;
    }

    void _lru_traverse_debug() {
        cout << "lru traverse debug: ";
        for (_node *cur = _head; cur != nullptr; cur = cur->lru_next) {
            cout << "{" << cur->key << ", " << cur->value << "}  ";
        }
        cout << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

O(n)的链表实现
```
// 执行用时 :364 ms, 在所有 C++ 提交中击败了5.26% 的用户
// 内存消耗 :39.9 MB, 在所有 C++ 提交中击败了55.66%的用户

// LRU - 链表实现
// get - O(n), put - O(n)

class LRUCache {
private:
    list<pair<int, int>> _cache;
    int _capacity;
public:
    LRUCache(int capacity) : _capacity(capacity) {
    }
    
    int get(int key) {
        for (auto it = _cache.begin(); it != _cache.end(); ++it) {
            if (it->first == key) {
                // 更新该节点位置
                int ret = it->second;
                _cache.erase(it);
                _cache.push_front({ key, ret });
                return ret;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {

        // 检查队列中是否有相同的key, 如果有则移除
        for (auto it = _cache.begin(); it != _cache.end(); ++it) {
            if (it->first == key) {
                _cache.erase(it);
                break;
            }
        }

        if (_cache.size() == _capacity) {
            // 淘汰cache中最近最久未使用的
            _cache.pop_back();
        }

        // 添加
        _cache.push_front({ key, value });
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```