### 解题思路
此处撰写解题思路

### 代码

```cpp
class LRUCache {
    
private:
    // 内部实现了哈希表，key：int value：list<pair<int,int>>::iterator 迭代器保存list中节点的地址，方便移动节点
    unordered_map<int, list<pair<int,int>>::iterator> _m;
    // 新节点或刚访问的节点插入表头，因为表头指针可以通过 begin 很方便的获取到。
    list<pair<int,int>> _list;
    // LRUCache缓存容量
    int _cap;
    
public:
    // 构造函数
    LRUCache(int capacity): _cap(capacity) {}
    
    // O(1)
    // 如果key存在于缓存中，则获取value，把 list 中的节点接下来移到头部
    int get(int key) {
        // 使用迭代器iterator从unordered_map中查找key对应的迭代器，迭代器指向list中的节点
        auto it = _m.find(key);
        if (it == _m.end()) return -1;
        // first会得到key，second会得到value，
        int val = it->second->second;
        // 列表删除该节点
        _list.erase(it->second);
        // 将该节点从表头插入
        _list.push_front(make_pair(key, val));
        // 更新哈希表对应key的值
        _m[key] = _list.begin();
        return it->second->second;
    }
    
    // O(1)
    // 先查找key是否存在，如果存在，将节点移动到首部
    // 如果不存在，插入新节点。
    // 当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
    void put(int key, int value) {
        // 从unordered_map中查找key对应的迭代器，迭代器指向list中的节点
        auto it = _m.find(key);
        // 如果存在，列表删除该节点
        if (it != _m.end()) {
            _list.erase(it->second);
        }
        // 将该节点从表头插入
        _list.push_front(make_pair(key, value));
        // 更新哈希表对应key的值
        _m[key] = _list.begin();
        // 如果容量达到上限
        if (_list.size() > _cap) {
            // 获取链表最后一个元素的key，哈希表删除该key，链表删除该元素
            int key = _list.back().first;
            _m.erase(key);
            _list.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
    
private:
    unordered_map<int, list<pair<int,int>>::iterator> _m;
    list<pair<int,int>> _list;
    int _cap;
    
public:
    LRUCache(int capacity): _cap(capacity) {}
    
    int get(int key) {
        auto it = _m.find(key);
        if (it == _m.end()) return -1;
        int val = it->second->second;
        _list.erase(it->second);
        _list.push_front(make_pair(key, val));
        _m[key] = _list.begin();
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = _m.find(key);
        if (it != _m.end()) {
            _list.erase(it->second);
        }
        _list.push_front(make_pair(key, value));
        _m[key] = _list.begin();
        if (_list.size() > _cap) {
            int key = _list.back().first;
            _m.erase(key);
            _list.pop_back();
        }
    }
};

int main() {
    LRUCache *cache = new LRUCache(2);
    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl;
    cache->put(3, 3);
    cout << cache->get(2) << endl;
    cache->put(4, 4);
    cout << cache->get(1) << endl;
    cout << cache->get(3) << endl;
    cout << cache->get(4) << endl;
}


```