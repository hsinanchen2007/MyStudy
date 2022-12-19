### 解题思路
关键是要知道用hash里要存：key->list中某元素的iterator
别忘了list中的位置更新后要重新获取iterator（通常在头部）存放在hash里。

### 代码

```cpp
class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) {
        auto find = _map.find(key);
        if (find == _map.end()) {
            return -1;
        }

        pair<int, int> kv = *(find->second);
        _list.erase(find->second);
        _list.push_front(kv);
        _map[key] = _list.begin();

        return kv.second;
    }

    void put(int key, int value) {
        auto find = _map.find(key);
        if (find != _map.end()) {
            pair<int, int> kv = *(find->second);
            _list.erase(find->second);
            kv.second = value;
            _list.push_front(kv);
            _map[key] = _list.begin();
            return;
        }

        pair<int, int> kv = make_pair(key, value);
        _list.push_front(kv);
        _map[key] = _list.begin();

        if (_list.size() > _capacity) {
            dieOut();
        }
        return;
    }

private:
    int _capacity;
    list<pair<int, int>> _list;
    unordered_map<int, list<pair<int, int>>::iterator> _map;

    void dieOut() {
        int key = _list.back().first;
        _list.pop_back();
        _map.erase(key);
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

![微信图片_20200112143833.png](https://pic.leetcode-cn.com/33e3f47cf2532b53e37582c6d044e542e0950f77f574a98a61f1f82ea76219d6-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200112143833.png)
