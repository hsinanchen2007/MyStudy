### 解题思路
这里的难点在于随机获取元素要满足`O(1)`就必须使用支持随机访问的容器，很自然地我们会想到`vector`，vector只有在最后添加或者删除元素时才是`O(1)`的。但我们在删除元素时并不一定删除末尾元素，比如删除中间某个元素，这时候我们需要在`O(1)`复杂度内定位要删除的元素，自然地哈希表具有这样的用途。

### 代码

```cpp
class RandomizedSet {
private:
    unordered_map<int, int> _lookup;
    vector<int> _data;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (_lookup.find(val) != _lookup.end()) {
            return false;
        } else {
            _data.push_back(val);
            _lookup[val] = _data.size() - 1;
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (_lookup.find(val) != _lookup.end()) {
            auto i = _lookup[val];
            if (i != _data.size() - 1) {
                _data[i] = _data.back();
                _lookup[_data[i]] = i;
            }
            _data.pop_back();
            _lookup.erase(val);
            return true;
        } else {
            return false;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r = std::rand() % _data.size();
        return _data[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```