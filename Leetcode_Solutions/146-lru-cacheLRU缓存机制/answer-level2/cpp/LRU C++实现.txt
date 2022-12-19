### 解题思路
1. 使用哨兵可以省去首尾空指针的判断
2. unordered map用的是散列表，查找插入都是O(1)

### 代码

```cpp
class LRUCache {
public:
    struct Node {
        int val;
        int key;
        Node *next;
        Node *pre;
        Node() : Node(0, 0, nullptr, nullptr) {}
        Node(int k, int v, Node* n = nullptr, Node *p = nullptr) { key = k; val = v; next = n; pre = p; }
    };
    LRUCache(int capacity) {
        capacity_ = capacity;
        //两个哨兵元素很有用的
        last_ = new Node();
        oldest_ = new Node();
/**
初始状态
Oldest.next---->Last
Oldest<--------Last.pre
**/
        last_->pre = oldest_;
        oldest_->next = last_;
    }
    ~LRUCache() { delete last_; delete oldest_;}
 
    int get(int key) {
        if (cache_.find(key) == cache_.end()) {
            // printf("Get(%d): %d\n", key, -1);
            return -1;
        } 
        // 更新链表
        cache_[key].next->pre = cache_[key].pre;
        cache_[key].pre->next = cache_[key].next;
        cache_[key].next = last_;
        cache_[key].pre = last_->pre;
        last_->pre->next = &cache_[key];
        last_->pre = &cache_[key]; 

        // last_->pre->next = &cache_[key];
        // printf("Get(%d):%d\n", key, cache_[key].val);
        return cache_[key].val;
    }
    
    void put(int key, int value) {
        if (cache_.find(key) != cache_.end()) {
            cache_[key].val = value;
            get(key);
            return;
        }
        cache_.emplace(key, value);
        cache_[key].next = last_;
        cache_[key].pre = last_->pre;
        last_->pre->next = &cache_[key];
        last_->pre = &cache_[key];
        if (cache_.size() > capacity_) {
            // 移除最旧的元素
            auto rm_key = oldest_->next->key;
            // std::cout << "About to remove " << rm_key << std::endl;
            oldest_->next->next->pre = oldest_;
            oldest_->next = oldest_->next->next;
            cache_.erase(rm_key);
        }
        
        // printf("Put(%d, %d)\n", cache_[key].key, cache_[key].val);
    }
private:
    unordered_map<int, Node> cache_;
    Node *last_ = nullptr; //哨兵元素，实际上last_->pre才是最近使用的
    Node *oldest_ = nullptr; //哨兵元素，实际上oldest_->next才是最少使用的
    int capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```