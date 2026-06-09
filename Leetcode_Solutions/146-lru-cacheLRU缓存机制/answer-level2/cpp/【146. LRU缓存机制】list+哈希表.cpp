### 思路
- list：保存key和value值
- unordered_map：保存key值和list迭代器之间映射关系


```
void splice( const_iterator pos, list& other, const_iterator it );//从other转移it所指向的元素到*this，元素被插入到pos所指向的元素之前
```

#### get
1. 查找哈希表看是否存在，如果不存在则返回-1
2. 如果存在，则移动到list头部(使用splice)
#### put
1. 查看哈希表看是否存在，如果存在，则删除
2. 将该key-value放入list头部并更新哈希表
3. 如果哈希表超过容量，则删除尾部元素同时从list中删除尾部元素
### 代码

```cpp
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = ump.find(key);
        if (it == ump.end()) return -1;
        li.splice(li.begin(), li, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = ump.find(key);
        if (it != ump.end()) li.erase(it->second);
        li.push_front({key, value});
        ump[key] = li.begin();
        if (ump.size() > cap) {
            int k = li.rbegin()->first;
            li.pop_back();
            ump.erase(k);
        }
    }
private:
    int cap;
    list<pair<int, int>> li;
    unordered_map<int, list<pair<int, int>>::iterator> ump;
};
```