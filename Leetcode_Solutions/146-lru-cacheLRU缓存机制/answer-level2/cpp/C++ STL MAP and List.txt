### 解题思路
创建 list 和 unordered_map 结构
其中 list 对象包含 key, value 
unordered_map 的 key 为 list 对象的 key, 其 value 为 list 的 iterator
1. put
    如果值已经存在unordered_map 则更新值， 并将 list中的这个值提到最前面
    如果不存在, 则删除 list 最后面的值， 并删除 unordered_map 这个对应的条目， 将新的值放在 list 最前，并在unordered_map 加上这个条目
2. get
    如果不存在则返回1
    如果存在，则将这个值移动 list 最前，并从 unordered_map 返回这个值

### 代码

```cpp
class LRUCache {
public:
    LRUCache(int capacity): _capacity(capacity){
    }
    
    int get(int key) {
        auto index = um.find(key);
        if(index == um.end())
            return -1;
        else
        {   lp.splice(lp.begin(), lp, index->second);
            return index->second->second;
        }
    }
    
    void put(int key, int value) {
        auto index = um.find(key);
        if(index != um.end()) {
           // update the lp and um
           lp.splice(lp.begin(), lp, index->second);
           index->second->second = value;
           return;
        }
        if(_capacity == um.size()) {
            // remove tha last
            auto key_to_del = lp.back().first;
            lp.pop_back();
            um.erase(key_to_del);
        }
        lp.emplace_front(key, value);
        um[key] = lp.begin();
    }

private:
    list<pair<int, int>> lp;
    unordered_map<int, list<pair<int, int>>::iterator> um;
    int _capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```