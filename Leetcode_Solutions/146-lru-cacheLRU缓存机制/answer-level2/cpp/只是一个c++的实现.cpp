### 解题思路
和高赞一样的解题思路，c++的实现。双向链表recent中越靠前越least recently.

### 代码

```cpp
typedef int key;

class LRUCache {
private:
    int capacity;
    unordered_map<int, list<pair<key, int>>::iterator> M;
    list<pair<key, int>> recent;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto keyIter = M.find(key);
        if (keyIter == M.end()) return -1;
        else {
            recent.push_back(*(keyIter->second));
            recent.erase(keyIter->second);
            keyIter->second = prev(recent.end());
            return recent.back().second;
        }
    }
    
    void put(int key, int value) {
        auto keyIter = M.find(key);
        if (keyIter == M.end()) {
            if (recent.size() == capacity) {
                M.erase(recent.front().first);
                recent.erase(recent.begin());
            }
            recent.push_back(make_pair(key, value));
            M[key] = prev(recent.end());
        }
        else {
            recent.push_back(make_pair(key, value));
            recent.erase(keyIter->second);
            keyIter->second = prev(recent.end());
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```