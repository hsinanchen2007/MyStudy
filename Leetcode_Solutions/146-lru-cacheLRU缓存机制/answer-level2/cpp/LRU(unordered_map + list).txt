### 解题思路
list存储<key,value>对
unordered_map主要存储key到list节点的迭代器的映射(可以理解为指针)
由于哈希表和链表的操作时间复杂度都是O(1),因此可以保证get和put的时间复杂度为O(1)

get:
使用哈希表查询，不存在返回-1，存在返回对应的值并把该节点移动到链表头
put:
使用哈希表查询key，若存在，先从链表删除，并把新的<key,value>对插入链表头，更新哈希表
若数量超过capacity，则删除链表最后的元素和map中对应的元素

### 代码

```cpp
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto iter = m.find(key);
        if(iter == m.end()) return -1;
        l.splice(l.begin(),l,iter->second);
        return iter->second->second;
    }
    
    void put(int key, int value) {
        auto iter = m.find(key);
        if(iter != m.end()) l.erase(iter->second);
        l.push_front(make_pair(key,value));
        m[key] = l.begin();
        if(l.size() > cap){
            int k = l.rbegin()->first;
            m.erase(k);
            l.pop_back();
        }
    }
    
private:
    int cap;
    typedef list<pair<int,int>> list_t;
    list_t l;
    unordered_map<int,list_t::iterator> m;
    
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```