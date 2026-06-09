### 解题思路
首先题目有问题，如果当出现相同频率多个数据时应该优先删除很久未访问过的那个，而不是啥最近的。= =
题目有两种思路，用set的平衡二叉树作为频率排序的数据结构
另一个思路是用双哈希表，一个key哈希表的键就是输入数据的键，一个哈希表key是出现频率，然后每次put和get都要更新频率，这道题只需要在数据超过容量时变动key哈希,其他时候只要改变频率哈希表就行。freq哈希的值为一个Node的链表，因为其可能有相同频率下几个Node,体现数据的时间性就是通过push数据的时候把数据放在链表前面，pop数据的时候从链表最后移除数据来体现。
此外由于key哈希表删除时需要freq哈希表，而且在根据频率相同删除很久未访问的数据的规则，需要建立key哈希和freq哈希的关系，而key可以通过iterator在多余容器容量删除时用erase操作，在添加新数据时通过iterator=freqNodelist.begin()来建立联系;
至于Node节点数据定义，在代码操作中哈希表增加删减时都会用到这几个数据类型，所以缺一不可。
此外就是注意初始化的clear()，本题倒是有没有没什么影响，还有就是capcity判断是否为0，以及哈希表是否为空，以及注意erase掉节点后，该节点将被抹去，iterator就失效了，所以需要提前保存该节点的val\freq值，不然会报heap free的错误

### 代码

```cpp
class LFUCache {
public:
    LFUCache(int capacity):capacity_(capacity) {
        val_map.clear();
        freq_map.clear();
    }
    
    int get(int key) {
        if(val_map.empty() || capacity_ == 0)
            return -1;
        auto iter = val_map.find(key);
        if(iter == val_map.end())
            return -1;
        else{
            list<Node>::iterator curNode = val_map[key];
            int freq = curNode->freq, val = curNode->val;
            freq_map[freq].erase(curNode);
            if(freq_map[freq].size() == 0){
                freq_map.erase(freq);
                if(min_freq == freq){
                    min_freq++;
                }
            }
            freq_map[freq+1].push_front(Node(key,val,freq+1));
            val_map[key] = freq_map[freq+1].begin();
        }
        return val_map[key]->val;
    }
    
    void put(int key, int value) {
        if(capacity_ == 0)
            return;
        auto iter = val_map.find(key);
        if(iter == val_map.end()){
            if(val_map.size() == capacity_){
                val_map.erase(freq_map[min_freq].back().key);
                freq_map[min_freq].pop_back();
                if(freq_map[min_freq].size() == 0){
                    freq_map.erase(min_freq);
                }
            }
            min_freq = 1;
            freq_map[1].push_front(Node(key,value,1));
            val_map[key] = freq_map[1].begin();
        }
        else{
            list<Node>::iterator curNode = val_map[key];
            int freq = curNode->freq;
            freq_map[freq].erase(curNode);
            if(freq_map[freq].size() == 0){
                freq_map.erase(freq);
                if(min_freq == freq){
                    min_freq++;
                }   
            }
            freq_map[freq+1].push_front(Node(key,value,freq+1));
            val_map[key] = freq_map[freq+1].begin();
        }
    }
private:
    struct Node{
        int key,val,freq;
        Node(int _key,int _val,int _freq):key(_key),val(_val),freq(_freq){}
    };
    unordered_map<int,list<Node>::iterator> val_map;
    unordered_map<int,list<Node>> freq_map;
    int capacity_;
    int min_freq = 1;
};



/**
struct Node {
    int cnt, time, key, value;

    Node(int _cnt, int _time, int _key, int _value):cnt(_cnt), time(_time), key(_key), value(_value){}
    
    bool operator < (const Node& rhs) const {
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};
class LFUCache {
    // 缓存容量，时间戳
    int capacity, time;
    unordered_map<int, Node> key_table;
    set<Node> S;
public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        time = 0;
        key_table.clear();
        S.clear();
    }
    
    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        // 如果哈希表中没有键 key，返回 -1
        if (it == key_table.end()) return -1;
        // 从哈希表中得到旧的缓存
        Node cache = it -> second;
        // 从平衡二叉树中删除旧的缓存
        S.erase(cache);
        // 将旧缓存更新
        cache.cnt += 1;
        cache.time = ++time;
        // 将新缓存重新放入哈希表和平衡二叉树中
        S.insert(cache);
        it -> second = cache;
        return cache.value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // 如果到达缓存容量上限
            if (key_table.size() == capacity) {
                // 从哈希表和平衡二叉树中删除最近最少使用的缓存
                key_table.erase(S.begin() -> key);
                S.erase(S.begin());
            }
            // 创建新的缓存
            Node cache = Node(1, ++time, key, value);
            // 将新缓存放入哈希表和平衡二叉树中
            key_table.insert(make_pair(key, cache));
            S.insert(cache);
        }
        else {
            // 这里和 get() 函数类似
            Node cache = it -> second;
            S.erase(cache);
            cache.cnt += 1;
            cache.time = ++time;
            cache.value = value;
            S.insert(cache);
            it -> second = cache;
        }
    }
};
 */
```