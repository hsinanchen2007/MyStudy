# 两种缓存算法
+ LRU
+ LFU
## [LRU: Least Recently Used](https://leetcode-cn.com/problems/lru-cache/)

获取键 / 检查键是否存在  
设置键  
删除最先插入的键
### 分析
既然要$O(1)$时间内完成，那肯定要用哈希表  
只用哈希表只能实现`get(key)`功能，还要存储每个`key`的使用次数的话，就要加上双向链表  
哈希表和双向链表应该怎么结合（套）在一起呢？

[From here](https://leetcode-cn.com/problems/lru-cache/solution/lru-ce-lue-xiang-jie-he-shi-xian-by-labuladong/)  
“那么，什么数据结构同时符合上述条件呢？哈希表查找快，但是数据无固定顺序；链表有顺序之分，插入删除快，但是查找慢。所以结合一下，形成一种新的数据结构：哈希链表。”  

[无效的图片地址](https://raw.githubusercontent.com/doutv/Picbed/master/img/4-12-2020-04-07-14-53-42)

哈希表里面的`value`存储的是双向链表中的节点`node`，双向链表中按访问时间由近到远排序。  
每次`get`就更新`key`对应的`node`顺序，把`node`放到双向链表的头部。  
每次`put`的时候，都要把当前节点`now`放到双向链表的头部，如果找不到`key`，就插入`key`，如果找到`key`，就更新`value`。如果插入新的`key`时缓存满了，就把双向链表的尾部丢掉。

### code
手写双向链表+`unordered_map`
1. 初始化`nullptr`
2. `lift_now_to_head`把`now`节点插入到链表头部
3. `unordered_map`直接用下标访问`m[key]`
4. `m.erase(last->key)`+`delete last`释放空间
```cpp
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
class MyListNode
{
public:
    int key;
    int val;
    MyListNode *pre;
    MyListNode *nxt;
    MyListNode(int k, int v)
    {
        key = k;
        val = v;
        pre = nullptr;
        nxt = nullptr;
    }
};
class LRUCache
{
public:
    MyListNode *head;
    MyListNode *tail;
    unordered_map<int, MyListNode *> m;
    int cap;
    int now_size;
    LRUCache(int capacity)
    {
        now_size = 0;
        cap = capacity;
        head = new MyListNode(-1, -1);
        tail = new MyListNode(-1, -1);
        head->nxt = tail;
        tail->pre = head;
    }
    void lift_now_to_head(MyListNode *now)
    {
        if (now->pre != nullptr && now->nxt != nullptr)
        {
            now->pre->nxt = now->nxt;
            now->nxt->pre = now->pre;
        }
        now->nxt = head->nxt;
        now->pre = head;
        head->nxt->pre = now;
        head->nxt = now;
    }
    int get(int key)
    {
        if (m.find(key) == m.end())
        {
            return -1;
        }
        MyListNode *now = m[key];
        lift_now_to_head(now);
        return now->val;
    }
    void put(int key, int value)
    {
        MyListNode *now;
        if (m.find(key) == m.end())
        {
            now = new MyListNode(key, value);
            if (now_size < cap)
            {
                now_size++;
                m[key] = now;
            }
            else
            {
                MyListNode *last = tail->pre;
                last->pre->nxt = tail;
                tail->pre = last->pre;
                m.erase(last->key);
                delete last;
                m[key] = now;
            }
        }
        else
        {
            now = m[key];
            now->val = value;
        }
        lift_now_to_head(now);
    }
};

```
## [LFU: Least Frequently Used](https://leetcode-cn.com/problems/lfu-cache/)
[From here:](https://leetcode-cn.com/problems/lfu-cache/solution/ha-xi-biao-shuang-xiang-lian-biao-java-by-liweiwei/)  
本题其实就是在[LRU](https://leetcode-cn.com/problems/lru-cache/)的基础上，在删除策略里多考虑了一个维度（「访问次数」）的信息。” 
核心思想：先考虑访问次数，在访问次数相同的情况下，再考虑缓存的时间。

[题解](https://leetcode-cn.com/problems/lfu-cache/solution/java-13ms-shuang-100-shuang-xiang-lian-biao-duo-ji/)  
1个哈希表+2个双向链表  
+ 哈希表`time_map`：`key-Node`  `Node`里面存`value` `freq` `freq_node`
+ 双向链表`FreqListNode`：按访问次数从大到小排列    
+ 双向链表`TimeListNode`：按访问时间从近到远排列（LRU中的双向链表）

P.S.先声明两个class`FreqListNode`和`TimeListNode`，就可以互相引用了  

![LFU](https://pic.leetcode-cn.com/25ade03ee7f3cbfdef0ddf955c917cde96f4153ba5ce8b321f42152b19d55ca5-LFU%E7%AE%97%E6%B3%95%E6%80%9D%E6%83%B3.png)

+ `get`：  
直接访问`key`对应的`TimeListNode`获取`value`，并更新当前`TimeListNode`的`freq`，把当前`TimeListNode`放到的下一个`FreqListNode`上

+ `put`：
1. `key`存在，更新`value`和`freq`，更新`freq`要把`TimeListNode`取出来放到下一个`FreqListNode`上
2. `key`不存在  
   1. 缓存满了：删掉`freq`最小且访问时间最远的节点，即为`FreqList`的尾部的`TimeList`尾部，然后进行`2.ii`
   2. 缓存没满：插入新节点，放在`freq=1`的`FreqListNode`上的头部

### code
满满的，都是坑啊  
手写两个双向链表是非常好的锻炼机会[狗头]

```cpp
#include <unordered_map>
using namespace std;
const int INF = 1 << 30;
// first declare
class FreqListNode;
class TimeListNode;
class TimeListNode
{
public:
    int key;
    int val;
    int freq;
    TimeListNode *pre;
    TimeListNode *nxt;
    FreqListNode *freq_node;
    TimeListNode(int k, int v)
    {
        key = k;
        val = v;
        freq = 1;
        freq_node = nullptr;
        pre = nullptr;
        nxt = nullptr;
    }
};
class FreqListNode
{
public:
    int freq;
    FreqListNode *pre;
    FreqListNode *nxt;
    TimeListNode *time_head;
    TimeListNode *time_tail;
    FreqListNode(int f)
    {
        freq = f;
        pre = nullptr;
        nxt = nullptr;
        time_head = new TimeListNode(-1, -1);
        time_tail = new TimeListNode(-1, -1);
        time_head->nxt = time_tail;
        time_tail->pre = time_head;
    }
};
class LFUCache
{
public:
    FreqListNode *freq_head;
    FreqListNode *freq_tail;
    unordered_map<int, TimeListNode *> time_map;
    int cap;
    int now_size;
    LFUCache(int capacity)
    {
        now_size = 0;
        cap = capacity;
        freq_head = new FreqListNode(INF);
        freq_tail = new FreqListNode(0);
        freq_head->nxt = freq_tail;
        freq_tail->pre = freq_head;
    }
    void erase_empty_FreqListNode(FreqListNode *now_freq)
    {
        if (now_freq->time_head->nxt == now_freq->time_tail)
        {
            now_freq->pre->nxt = now_freq->nxt;
            now_freq->nxt->pre = now_freq->pre;
            delete now_freq;
        }
    }
    void incre_freq(TimeListNode *now)
    {
        now->pre->nxt = now->nxt;
        now->nxt->pre = now->pre;
        now->freq += 1;
        FreqListNode *now_freq = now->freq_node;
        FreqListNode *nxt_freq = now_freq->pre;
        if (nxt_freq->freq > now->freq)
        {
            nxt_freq = new FreqListNode(now->freq);
            now_freq->pre->nxt = nxt_freq;
            nxt_freq->pre = now_freq->pre;
            nxt_freq->nxt = now_freq;
            now_freq->pre = nxt_freq;
        }
        now->freq_node = nxt_freq;
        lift_now_to_head(now);
        erase_empty_FreqListNode(now_freq);
    }
    void insert_TimeListNode(TimeListNode *now)
    {
        FreqListNode *now_freq;
        if (freq_tail->pre != nullptr && freq_tail->pre->freq == 1)
        {
            now_freq = freq_tail->pre;
        }
        else
        {
            now_freq = new FreqListNode(1);
            freq_tail->pre->nxt = now_freq;
            now_freq->pre = freq_tail->pre;
            now_freq->nxt = freq_tail;
            freq_tail->pre = now_freq;
        }
        now->freq_node = now_freq;
        now->freq = 1;
        TimeListNode *time_head = now_freq->time_head;
        time_head->nxt->pre = now;
        now->nxt = time_head->nxt;
        now->pre = time_head;
        time_head->nxt = now;
    }
    void delete_last_TimeListNode()
    {
        FreqListNode *now_freq_node = freq_tail->pre;
        TimeListNode *time_tail = now_freq_node->time_tail;
        TimeListNode *now = time_tail->pre;
        time_map.erase(now->key);
        now->pre->nxt = time_tail;
        time_tail->pre = now->pre;
        delete now;
        erase_empty_FreqListNode(now_freq_node);
    }
    void lift_now_to_head(TimeListNode *now)
    {
        FreqListNode *now_freq = now->freq_node;
        TimeListNode *head = now_freq->time_head;
        TimeListNode *tail = now_freq->time_tail;
        now->nxt = head->nxt;
        now->pre = head;
        head->nxt->pre = now;
        head->nxt = now;
    }
    int get(int key)
    {
        if (time_map.find(key) == time_map.end())
        {
            return -1;
        }
        TimeListNode *now = time_map[key];
        incre_freq(now);
        return now->val;
    }
    void put(int key, int value)
    {
        TimeListNode *now;
        if (!cap)
            return;
        if (time_map.find(key) == time_map.end())
        {
            now = new TimeListNode(key, value);
            if (now_size < cap)
            {
                now_size++;
                time_map[key] = now;
                insert_TimeListNode(now);
            }
            else
            {
                delete_last_TimeListNode();
                time_map[key] = now;
                insert_TimeListNode(now);
            }
        }
        else
        {
            now = time_map[key];
            now->val = value;
            incre_freq(now);
        }
    }
};
```