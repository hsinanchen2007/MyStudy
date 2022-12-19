### 解题思路
此处撰写解题思路

### 代码

```cpp
struct Node{
    int cnt,time,key,value;
    Node(int _cnt,int _time,int _key,int _value){
        cnt = _cnt;
        time = _time;
        key = _key;
        value = _value;
    }
    bool operator < (const Node& rhs)const{
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};
class LFUCache {
    int capacity,time;
    unordered_map<int,Node> key_table;
    set<Node> Set;
public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        time = 0;
        key_table.clear();
        Set.clear();
    }
    
    int get(int key) {
        auto it = key_table.find(key);
        if(it == key_table.end()) return -1;
        Node cache = it->second;
        Set.erase(cache);
        cache.cnt++;
        cache.time = ++time;
        Set.insert(cache);
        it->second = cache;
        return cache.value;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        auto it = key_table.find(key);
        if(it == key_table.end()){
            if(key_table.size() == capacity){
                key_table.erase(Set.begin()->key);
                Set.erase(Set.begin());
            }
            Node cache = Node(1,++time,key,value);
            key_table.insert(make_pair(key,cache));
            Set.insert(cache);
            }
        else{
            Node cache = it->second;
            Set.erase(cache);
            cache.cnt++;
            cache.time = ++time;
            cache.value = value;
            Set.insert(cache);
            it->second = cache;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
