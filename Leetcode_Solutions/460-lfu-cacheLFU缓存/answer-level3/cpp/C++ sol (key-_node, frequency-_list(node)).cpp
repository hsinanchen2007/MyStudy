### 解题思路
1. 跟 LRU 类似的，创建 key->node 的hash表，其中node 要包含 freq（频率） 和 it（指向对应双向链表的指针）
2. node当中的freq的作用是，通过key我们可以找到对应的node，而对应node的访问频率可以找到对应的双向链表 O(1)
3. node当中的it的作用是，我们在第2步找到的对应链表，可以通过it找到其在双向链表的准确位置O(1)
4. 需要注意的是put 操作，如果capacity已满，则删除频率最低的链表当中末尾的元素，当该链表为空时，还要从 cache 当中移除
5. 在put时，如果capacity没有满，则直接插入元素，其访问频率初始化成1
6. 特别需要注意的是，get时也有一个put操作，这是为了更新当前node的频率在m与cache当中的位子。

### 代码

```cpp
struct Node {
    Node(int key, int val, int freq) : key(key), val(val), freq(freq) {}

    int key{-1};
    int val{-1};
    int freq{-1};
    list<Node*>::iterator it{};
};

class LFUCache {
private:
    unordered_map<int, Node*> m; // key -> node
    unordered_map<int, list<Node*>> cache; // frequency -> list(node)
    int capacity{0};

public:
    LFUCache(int capacity) : capacity (capacity) { }
    
    int get(int key) {
        auto it = m.find(key);
        if (m.end() == it) {
            return -1;
        }

        int val = it->second->val;
        put(key, val);

        return val;
    }
    
    void put(int key, int value) {
        if (capacity <= 0) return;

        auto it = m.find(key);
        if (m.end() != it) {
            Node* node = it->second;
            int freq = node->freq;
            list<Node*>& freqList = cache[freq];

            freqList.erase(node->it);
            if (freqList.empty()) cache.erase(freq);
            
            cache.insert({freq+1, {}});
            cache[freq+1].push_front(node);
            
            node->it = cache[freq+1].begin();
            node->val = value;
            node->freq += 1;
        } else {
            if (m.size() == capacity) {
                int minFreq = INT_MAX;
                for (auto it : m) {
                    minFreq = min(minFreq, it.second->freq);
                }
                
                list<Node*>& freqList = cache[minFreq];
                Node* deleteNode = freqList.back();
                int deleteKey = deleteNode->key;

                freqList.pop_back();
                delete deleteNode;
                if (freqList.empty()) cache.erase(minFreq);

                m.erase(deleteKey);
            }

            Node* node = new Node(key, value, 1);
            cache.insert({1, {}});
            cache[1].push_front(node);
            node->it = cache[1].begin();
            m[key] = node;
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