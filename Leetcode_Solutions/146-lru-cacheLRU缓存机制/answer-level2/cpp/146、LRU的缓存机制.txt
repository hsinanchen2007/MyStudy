### 解题思路
使用list 和 unordered_map构成有序的双向链表。
```
    // 双链表：装 (key, value) 
    list<pair<int, int>> l;
    // 哈希表：key 对应 (key, value) 在 l 中的位置iterator
    unordered_map<int, list<pair<int, int>>::iterator> m;


```
注意，通过m[key]获取list中位置的迭代器it，再通过迭代器访问list中的键值对。
每次更新list，不要忘了吧map中对应的迭代器也更新。
get方法中要注意，如果访问存在，要放到队头去。
put中要注意，如果已经满了，那么要删除队尾，再更新到队头，如果key存在，则更新key-val对，并放到队头。

### C++代码

```cpp
class LRUCache {
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it == m.end())
        {
            return -1;
        }
        else
        {
            pair<int,int> tmp = *m[key];
            l.erase(m[key]);
            l.push_front(tmp);
            m[key] = l.begin();
            return tmp.second;
        }
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if(it == m.end()) //如果不存在
        {
           if(cap == l.size())
           {
               //如果已经满了，那么要删除队尾，再更新到队头
               m.erase(l.back().first);
               l.pop_back();
               pair<int,int> tmp = make_pair(key,value);
                l.push_front(tmp);
                m.insert(make_pair(key,l.begin()));
           }
           else
           {
            //如果不存在，缓存还没满，那么应该放在队头
           pair<int,int> tmp = make_pair(key,value);
           l.push_front(tmp);
           m.insert(make_pair(key,l.begin()));
           }
        }
        else //如果key存在，则更新key-val对，并放到队头
        {
            l.erase(m[key]);
            pair<int,int> tmp = make_pair(key,value);
            l.push_front(tmp);
            m[key] = l.begin();
        }
    }
public:
    int cap;
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```