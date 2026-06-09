## [删除最久未使用的数据值](https://leetcode-cn.com/problems/lru-cache/)
获取键 / 检查键是否存在  
设置键  
删除最先插入的键
### 分析
既然要$O(1)$时间内完成，那肯定要用哈希表  
只用哈希表只能实现`get(key)`功能，还要存储每个`key`的使用次数的话，就要加上双向链表  
哈希表和双向链表应该怎么结合（套）在一起呢？

[From here](https://leetcode-cn.com/problems/lru-cache/solution/lru-ce-lue-xiang-jie-he-shi-xian-by-labuladong/)  
“那么，什么数据结构同时符合上述条件呢？哈希表查找快，但是数据无固定顺序；链表有顺序之分，插入删除快，但是查找慢。所以结合一下，形成一种新的数据结构：哈希链表。”  

![4-12-2020-04-07-14-53-42](https://pic.leetcode-cn.com/4ebfe6cc155ade071622061dcfd5c165e7c4afd75da9721d27826b50f3b855ca)

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