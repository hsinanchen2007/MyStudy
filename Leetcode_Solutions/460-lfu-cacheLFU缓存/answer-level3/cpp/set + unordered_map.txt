### 解题思路
此处撰写解题思路
std::pair<int, Node>(key, node);
std::make_pair(key, node);

### 代码

```cpp
struct Node{
    int key;
    int value;
    int fre; // access num
    int time; // last acc time;
    Node(int _key, int _value, int _fre, int _time):key(_key), value(_value), fre(_fre), time(_time){

    }
    bool operator< (const Node& rhs) const{
        return this->fre == rhs.fre ? this->time < rhs.time : this->fre < rhs.fre;
    }
};
class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        time = 0;
    }
    
    int get(int key) {
        if(this->capacity <= 0) return -1;
        ++(this->time);
        auto it = mp.find(key);
        if(it == mp.end()) return -1;
        Node cache = it->second;
        st.erase(cache);
        cache.time = this->time;
        cache.fre++;
        st.insert(cache);
        it->second = cache;
        return cache.value;
    }
    
    void put(int key, int value) {
        if(this->capacity <= 0) return;
        ++(this->time);
        if(mp.find(key) != mp.end()){
            auto it = mp.find(key);
            Node cache = it->second;
            st.erase(cache);
            cache.time = this->time;
            cache.fre++;
            cache.value = value;
            st.insert(cache);
            it->second = cache;
        }else if(mp.size() == this->capacity){
            Node deleted = *st.begin();
            st.erase(deleted);
            mp.erase(deleted.key);
            Node cur = Node(key, value, 1, this->time);
            mp.insert(std::pair<int,Node>(key, cur));
            st.insert(cur);
        }else{
            Node cur = Node(key, value, 1, this->time);
            mp.insert(pair<int,Node>(key, cur));
            st.insert(cur);
        }
    }
private:
    int time = 0;
    int capacity;
    unordered_map<int, Node> mp;
    set<Node> st;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```