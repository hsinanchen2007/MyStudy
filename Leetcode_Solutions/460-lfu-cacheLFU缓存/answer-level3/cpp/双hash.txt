

### 代码

```cpp
struct Node 
{
    int key, val, cnt;
    Node(int _key, int _val, int _cnt): key(_key), val(_val), cnt(_cnt) {}
};

class LFUCache {
private:
    unordered_map<int, list<Node>::iterator> cache;
    unordered_map<int, list<Node>> freq;
    int minFreq;
    int capacity;
    
    //频率加一，调整位置
    list<Node>::iterator freqInc(list<Node>::iterator it)
    {
        Node cur = *it;
        freq[cur.cnt].erase(it);
        if(freq[cur.cnt].empty())
        {
            freq.erase(cur.cnt);
            if(minFreq == cur.cnt) minFreq++;
        }
        freq[++cur.cnt].push_front(cur);
        cache[cur.key] = freq[cur.cnt].begin();
        return cache[cur.key];
    }

public:   
    LFUCache(int _capacity): minFreq(0), capacity(_capacity) {}
  
    int get(int key) 
    {
        if(capacity == 0) return -1;
        auto it = cache.find(key);
        if(it == cache.end()) return -1;
        return freqInc(it->second)->val;       
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        auto it = cache.find(key);
        if(it == cache.end())
        {
            //淘汰最近不经常使用的数据
            if(cache.size() == capacity)
            {
                Node lfu = freq[minFreq].back();
                cache.erase(lfu.key);
                freq[minFreq].pop_back();  
                if(freq[minFreq].empty()) freq.erase(minFreq); 
            }
            minFreq = 1;
            freq[minFreq].push_front(Node(key, value, minFreq));
            cache[key] = freq[minFreq].begin();
        }
        else
        {
            it->second->val = value;
            freqInc(it->second);
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