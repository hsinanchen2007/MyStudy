说明：此处代码借鉴***的创始人，如果有要面试笔试的同学，可以去***学习，作者主攻c++，讲解很详细，对我帮助很大。
本题思想就是开一个大数组，在哈希表中的每个位置上，用一个链表来存储所有映射到该位置的元素，避免冲突。
```
class MyHashMap {
public:
    /** Initialize your data structure here. */
    int N = 2000013;
    vector<list<pair<int,int>>> h;
    MyHashMap() {
        h = vector<list<pair<int,int>>>(N);
    }
    
    list<pair<int,int>>::iterator find(int key)
    {
        int t = key % N;
        for(auto it = h[t].begin();it != h[t].end();it++)
        {
            if(it->first == key)
                return it;
        }
        return h[t].end();
    }
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto it = find(key);
        int t = key % N;
        if(it == h[t].end()) h[t].push_back(pair(key,value));
        else it->second = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto it = find(key);
        int t = key % N;
        if(it == h[t].end()) return -1;
        return it->second;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto it = find(key);
        int t = key % N;
        if(it!=h[t].end()) h[t].erase(it);
    }
};
```
