更多题解，尽在公众号：算法工程师之路
解题思路：

LRU算法可以用于缓存机制，也同样适用于页面置换算法！其思路为每次置换最近最久不访问的内存空间到磁盘中，具体措施是维护一个链表，当访问一个页面时， 将该页面移动到链表的头部，而链表的尾部始终为最近最久未访问的空间，当内存不够时，将链表尾部的空间进行置换即可！
![LRU.PNG](https://pic.leetcode-cn.com/4fba2211e4f6b803e72f64dddbf5e0c90c3af746b3e423997e759daf3616c317-LRU.PNG)

而在本题中，引入了缓存机制，由于缓存的数据可能重复，因此使用秘钥key加以区分，由于需要在链表的头部和尾部操作，应该使用双向链表list(STL中forward_list为单向链表)，list的成员应该为pair<int, int>，不然没有秘钥无法区分！大家都清楚，链表的查询是很慢的，必须从头到尾进行遍历，因此可以使用哈希表进行保存list的迭代器！
从而使用unordered_map<int, list<pair, pair>::iterator>, 这样做的好处就是：假设删除秘钥为key的节点，不用遍历在链表中查询了，可以O(1)的获取将要删除的节点的迭代器！即hashmap[key].

(STL库函数版本)
```c++
class LRUCache {
public:
    
    LRUCache(int capacity) : capacity_(capacity) {}
    
    int get(int key) {
        if(hashmap.count(key) == 0)
            return -1;
        else{
            int val = hashmap[key]->second;
            lis.erase(hashmap[key]);
            lis.push_front(make_pair(key, val));
            hashmap[key] = lis.begin();
            return val;
        }
    }
    
    void put(int key, int value) {
        if(hashmap.count(key) != 0){
            lis.erase(hashmap[key]);
        }else if (lis.size() >= capacity_){
            hashmap.erase(lis.back().first);
            lis.pop_back();   // 删除最近最久未访问的数据
        }
        lis.push_front(make_pair(key, value));
        hashmap[key] = lis.begin();  // 迭代器存入哈希表
    }
private:
    int capacity_;
    list<pair<int, int>> lis;
    unordered_map<int, list<pair<int, int>>::iterator> hashmap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
(手撸双向链表版本)
```c++
class LRUCache {
public:
    struct ListNode{
        ListNode* pre;
        ListNode* next;
        int key;
        int val;
        ListNode(int key_, int val_) : key(key_), val(val_), pre(nullptr), next(nullptr) {}
    };
    LRUCache(int capacity) : capacity_(capacity), cnt(0){
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head->next = tail;
        tail->pre = head;
    }

    void update(ListNode *p){  // 更新，将p节点删除，并移至头部
        if(p->pre == head) return;
        // 删除p节点操作
        p->pre->next = p->next;
        p->next->pre = p->pre;
        // 插入头部操作
        p->next = head->next;
        p->pre = head;
        head->next->pre = p;
        head->next = p;
    }
    
    int get(int key) {
        unordered_map<int, ListNode*>::iterator it = hashmap.find(key);
        if(it == hashmap.end()) return -1;
        ListNode *p = it->second;
        update(p);
        return p->val;
    }
    
    void put(int key, int value) {
        if(capacity_ <= 0) return;
        unordered_map<int, ListNode*>::iterator it = hashmap.find(key);
        if(it == hashmap.end()){    // 没有找到
            ListNode *p = new ListNode(key, value);
            hashmap[key] = p;
            p->next = head->next;
            p->pre = head;
            head->next->pre = p;
            head->next = p;
            cnt++;   // 节点加一
            if(cnt > capacity_){
                ListNode* pDel = tail->pre;   // 删除双向链表尾部节点
                pDel->pre->next = tail;
                tail->pre = pDel->pre;
                unordered_map<int, ListNode*>::iterator itDel = hashmap.find(pDel->key);
                hashmap.erase(itDel);
                delete pDel;
                cnt--;
            }
        }else{
            ListNode *p = it->second;
            p->val = value;
            update(p);
        }
    }
private:
    int capacity_;
    int cnt;   // 标记双向链表节点数
    unordered_map<int, ListNode*> hashmap;
    ListNode* head, *tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
