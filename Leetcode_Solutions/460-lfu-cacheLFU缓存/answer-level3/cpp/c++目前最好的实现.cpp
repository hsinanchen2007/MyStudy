![捕获.PNG](https://pic.leetcode-cn.com/4fd2e643c385d7f35016e73420c46b8e94beb2f23ee5360d64849f1313930140-%E6%8D%95%E8%8E%B7.PNG)
关键数据结构：
1.一个key排序的kvMap;
2.一个频率排序的feqMap,它的每一个value是LRU双链表。

```
class LFUCache {
private:
    int capacity;
    struct kvEntry {
        int val;
        int freq;
        list<int>::iterator iter;
        kvEntry(int v, int q,  list<int>::iterator it) {
            val = v;
            freq = q;
            iter = it;
        }
        kvEntry() {}
    };

    int minFre;
    unordered_map<int, kvEntry> kvTable;
    //       frequency   keys
    unordered_map<int, list<int>> freTable;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFre = 0;
    }
    
    int get(int key) {
        if (!capacity) {
            return -1;
        }
        //cout << "get: " << key << endl;
        if (kvTable.find(key) == kvTable.end()) {
            return -1;
        } else {
            int val = kvTable[key].val;
            put(key, val);
            return val;
        }
    }
    
    void put(int key, int value) {
        if (!capacity) {
            return;
        }
        //cout << "put: " << key << " " << value << endl;
        if (kvTable.find(key) == kvTable.end()) {
            if (kvTable.size() == capacity) {
                auto &l = freTable[minFre];
                int tmpKey = l.back();

                l.erase(prev(l.end()));
                kvTable.erase(tmpKey);
            }

            freTable[1].emplace_front(key);
            minFre = 1;

            kvTable[key].val = value;
            kvTable[key].freq = 1;
            kvTable[key].iter = freTable[1].begin();
        } else {
            int &freq = kvTable[key].freq;
            auto &it = kvTable[key].iter;

            // modify freq table
            auto &l = freTable[freq];
            l.erase(it);
            auto &l1 = freTable[freq + 1];
            l1.emplace_front(key);
            if (freq == minFre && freTable[freq].size() == 0) {
                minFre++;
            }

            // modify kv table;
            kvTable[key].val = value;
            kvTable[key].freq = freq + 1;
            kvTable[key].iter = l1.begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
