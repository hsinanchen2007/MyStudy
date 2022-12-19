### 双链表的用途
双链表用于存储最近访问的key，始终保持链表从头到尾，key的访问时间依此降低。
如果容量超出，直接从链表末尾删除一个key。

### 双哈希表的用途
第一个哈希表使用来支持get()函数，可以快速确认某个key是否存在
第二个哈希表用来保存每个key在LRU存储中的位置，方便快速删除和更新。

```cpp
class LRUCache {
public:

    list<int> q;                                        //LRU 存储
    unordered_map<int,int> hash;                        // 快速确认key是否存在
    unordered_map<int, list<int>::iterator> keyPos;     // 存储key在LRU中的位置，方便删除更新
    int sz;                                             // 容量
    LRUCache(int capacity) {
        sz = capacity;
        time = 0;
    }
    
    int get(int key) {
        if(hash.count(key) ==0) return -1;
        put(key, hash[key]);
        return hash[key];
    }
    
    void put(int key, int value) {
        // 不存在
        if(hash.count(key)==0){
            if(q.size() ==sz){
                int last_key = q.back();
                q.pop_back();
                hash.erase(last_key);
            }
            hash[key] = value;
            q.push_front(key);
            keyPos[key] = q.begin();
        }
        else{
            hash[key]= value;
            q.erase(keyPos[key]);
            q.push_front(key);
            keyPos[key] = q.begin();
        } 
    }
};
```
