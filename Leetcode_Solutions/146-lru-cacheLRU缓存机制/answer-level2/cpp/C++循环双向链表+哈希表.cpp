循环链表，每次更新时将元素放到head后面，evict时去掉head前面的那一项。

执行用时 :148 ms, 在所有 C++ 提交中击败了
88.44%
的用户

内存消耗 :
37.8 MB
, 在所有 C++ 提交中击败了
91.53%
的用户
```c++
struct Entry{
    int key;
    int val;
    Entry *next;
    Entry *last;
    Entry(int k, int v):key(k), val(v), next(this), last(this){}
};
class LRUCache {
public:
    int capacity;
    unordered_map<int, Entry*> cache;
    Entry *head;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Entry(0, 0);
    }
    
    int get(int key) {
        unordered_map<int, Entry*>::iterator it = cache.find(key);
        if (it == cache.end()){
            return -1;
        }
        else{
            update(it);
            return it->second->val;
        }
    }
    
    void put(int key, int value) {
        unordered_map<int, Entry*>::iterator it = cache.find(key);
        if (it != cache.end()){
            it->second->val = value;
            update(it);
            return;
        }
        if(capacity > 0){
            --capacity;
        }
        else{ // Evict
            Entry *evict = head->last;
            evict->last->next = head;
            head->last = evict->last;
            int evictKey = evict->key;
            cache.erase(evictKey);
            delete evict;
        }
        Entry *pst = new Entry(key, value);
        cache.insert(pair<int, Entry*>(key, pst));
        head->next->last = pst;
        pst->next = head->next;
        head->next = pst;
        pst->last = head;
    }
    
    void update(unordered_map<int, Entry*>::iterator it){
            it->second->last->next = it->second->next;
            it->second->next->last = it->second->last;
            head->next->last = it->second;
            it->second->next = head->next;
            it->second->last = head;
            head->next = it->second;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
