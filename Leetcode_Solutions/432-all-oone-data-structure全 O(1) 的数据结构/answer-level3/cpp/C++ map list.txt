### 解题思路
维持一个单调的list，在list中保存key和value；map中用key映射到list的iterator
inc时把对应元素和list前面的相比，把value较大的往前面交换
同理，dec时把对应元素和list后面的相比，把value较小的往后面交换

![image.png](https://pic.leetcode-cn.com/cd9f4fb15f678c878d21e6f6b6e72fb20ad578af0b45790a76826408fa29cfa3-image.png)


### 代码

```cpp
class AllOne {
public:
    list<pair<string, int>> m_list;
    unordered_map<string, list<pair<string, int>>::iterator> m_map;

    /** Initialize your data structure here. */
    AllOne() {

    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (m_map.count(key) == 0) {
            m_list.push_back({key, 1});
            m_map[key] = prev(m_list.end());
            return;
        }
        auto it = m_map[key];
        ++(it->second);
        auto pit = prev(it);
        while (it != m_list.begin() && it->second > pit->second) {
            iter_swap(it, pit);
            m_map[it->first] = it;
            m_map[pit->first] = pit;
            pit = prev(pit);
            it = prev(it);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (m_map.count(key) == 0) {
            return;
        }
        auto it = m_map[key];
        --(it->second);
        if (it->second == 0) {
            m_list.erase(it);
            m_map.erase(key);
            return;
        }
        auto nit = next(it);
        while (nit != m_list.end() && nit->second > it->second) {
            iter_swap(it, nit);
            m_map[it->first] = it;
            m_map[nit->first] = nit;
            nit = next(nit);
            it = next(it);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (m_list.empty()) {
            return "";
        }
        return m_list.begin()->first;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (m_list.empty()) {
            return "";
        }
        return prev(m_list.end())->first;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
```