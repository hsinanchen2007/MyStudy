

![image.png](https://pic.leetcode-cn.com/2046825625bfea938b1e3d4ff7e6b3b8c293b750a60c98e9b7fd1b79055134a9-image.png)

``` cpp
class LRUCache {
private:
    int _capacity;
    unordered_map<int, int> _kv;
    unordered_map<int, list<int>::const_iterator> _ki;
    list<int> _kl;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto it = _kv.find(key);
        if (it == _kv.end()) return -1;
        auto ki = _ki.find(key);
        _kl.splice(_kl.begin(), _kl, ki->second);
        return _kv[key];
    }
    
    void put(int key, int value) {
        if (_kv.find(key) != _kv.end()) {
            _kv[key] = value;
            auto ki = _ki.find(key);
            _kl.splice(_kl.begin(), _kl, ki->second);
            return;
        }
        _kv[key] = value;
        _kl.emplace_front(key);
        _ki[key] = _kl.begin();
        if (_kv.size() > _capacity) {
            _kv.erase(_kl.back());
            _ki.erase(_kl.back());
            _kl.pop_back();
        }
    }
};
```
