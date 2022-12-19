果然，状态不好的时候不适合刷题。。。
本来是做LFU的题目，结果误打误撞，做成了LRU，那么姑且将两种方法都分享下自己的见解。如有错误，欢迎指正。
1.LFU
a.基本概念
缓存的置换规则为缓存满时，每次插入新的元素需要淘汰掉使用频次最低的元素，当最低频次的元素有多个时，优先淘汰掉最近最久未使用的那个。
b.题目解读
题目中对于缓存有两种操作，分别为get，put。
get操作要求对于存在的key，根据其key返回value。
put操作要求对于已在缓存中存在的key，更新其value；对于不在缓存中的key，需要放入缓存中。对于需要放入缓存的key，首先需要判断缓存是否满，如果满，按照前述LFU的置换规则先淘汰一个元素，然后将key放入缓存中，否则直接将key放入缓存中。
c.注意事项
由于是LFU，根据其缓存置换规则，维护其缓存中每个元素的优先级至关重要。优先级有两个因素决定，一个是使用频次越低优先级越低，另一个是相同频次下按照使用时间的先后顺序，越早使用的优先级越低。每次置换时优先淘汰优先级最低的元素。
对于使用频次的统计，首先肯定可以明确的一点是每get操作一次，相应的元素使用频次加1，但这里需要说明的是在put操作时，如果相应的key在缓存中存在时除了更新value外也需要对该元素key的使用频次加1，这一点需要特别注意。
d.方法
根据上述的想法，我们使用一个带头结点的双向循环链表来实现对于缓存中元素优先级的维护。使用链表是为了每一次更新使用频次后方便对元素优先级进行调整（试想，如果使用数组的话可能涉及元素的移动），使用双向循环链表的原因是方便元素的查找，移动。
对于优先级，在双向循环链表中，我们规定使用频次越大的越靠近头结点，相同使用频次下，越是最近使用的排在同频次的靠前位置，即优先级越高的越靠近头结点。有了上述链表后，我们每次对缓存的插入和缓存中元素淘汰就变得很容易了，即每次插入，如果缓存满，首先淘汰掉链表最后一个节点，即优先级最底的结点，然后从链表尾部向前寻找一个合适的位置将新结点插入。
同时，我们为了提高检索速度，引入了一个hash表来加速查找。
因此，综上所述，链表负责维护所有结点的优先级，优先级越低在缓存满时优先淘汰。而hash表负责元素的查找。
e.LFU代码
```
class LFUCache {
private:
    struct node
    {
        int key;
        int value;
        int count;
        node* left;
        node* right;
        node(int k, int v, int c, node* l, node* r) 
        : key(k), value(v), count(c), left(l), right(r) {}
    };
    unordered_map<int, int> kv;
    int size = 0;
    node* head = NULL;
public:
    LFUCache(int capacity) {
        size = capacity;
        head = new node(0, 0, 0, NULL, NULL);
        head->left = head;
        head->right = head;
    }
    
    int get(int key) {
        // 缓存大小为0的情况
        if (size == 0) return -1;
        // 获取元素，如果存在，调整链表
        if (kv.count(key))
        {
            // 元素存在，调整使用频次，调整链表
            node* p = head->right;
            while(p != head)
            {
                if (p->key == key) break;
                p = p->right;
            }
            // 此k, v在kv中存在，则此结点一定在链表中存在
            p->count++;
            node* current = p;
            p = p->left;
            while (p != head && current->count >= p->count)
            {
                p = p->left;
            }
            if (p != current)
            {
                node* current_l = current->left;
                node* current_r = current->right;
                current_l->right = current_r;
                current_r->left = current_l;
                // 调整位置
                current->right = p->right;
                current->left = p;
                p->right->left = current;
                p->right = current;
            }
            return kv[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        // 缓存大小为0的情况
        if (size == 0) return;
        if (kv.count(key))
        {
            // 元素存在，调整使用频次，调整链表，同时置换新的value
            node* p = head->right;
            while(p != head)
            {
                if (p->key == key) break;
                p = p->right;
            }
            // 此k, v在kv中存在，则此结点一定在链表中存在，除非后面的插入代码有误
            p->value = value;
            p->count++;
            node* current = p;
            p = p->left;
            while (p != head && current->count >= p->count)
            {
                p = p->left;
            }
            if (p != current)
            {
                node* current_l = current->left;
                node* current_r = current->right;
                current_l->right = current_r;
                current_r->left = current_l;
                // 调整位置
                current->right = p->right;
                current->left = p;
                p->right->left = current;
                p->right = current;
            }
            // 更新kv
            kv[key] = value;
        }
        else
        {
            // 元素不存在，需要插入链表
            // 链表中结点按照从前置后按照使用频次递减的顺序排列
            // 对于相同频次的结点，最近插入的元组排在最前面
            if (kv.size() == size)
            {
                // 缓存已满，首先弃置链表最后一个元素，然后插入链表
                node* end = head->left;
                node* end_pre = end->left;
                head->left = end_pre;
                end_pre->right = head;
                // 更新kv
                kv.erase(end->key);
            }
            // 此时缓存未满，插入链表
            node* p = head->left;
            node* new_node = new node(key, value, 1, NULL, NULL);
            if (p == head)
            {
                // 链表中无节点，只有头结点，则直接插入
                head->right = new_node;
                head->left = new_node;
                new_node->left = head;
                new_node->right = head;
            }
            else
            {
                // 链表中存在其它结点，需要比较
                while(p != head && new_node->count >= p->count)
                {
                    p = p->left;
                }
                if (p == head)
                {
                    // 一直比较到头结点，表明链表中结点的使用频次均为1
                    new_node->right = head->right;
                    new_node->left = head;
                    head->right->left = new_node;
                    head->right = new_node;
                }
                else
                {
                    // 非头结点位置
                    new_node->right = p->right;
                    new_node->left = p;
                    p->right->left = new_node;
                    p->right = new_node;
                }
            }
            // 插入k,v
            kv[key] = value;
        }
    }
};
```
f.LRU
LRU由于比较简单，对于优先级的确定不要使用频次，只需要根据使用时刻的先后顺序来确定即可，因此这里可以用一个普通链表来实现。关于LRU的概念大家可自行百度。
题号：[146. LRU缓存机制](https://leetcode-cn.com/problems/lru-cache/)
```
class LRUCache {
private:
    struct node
    {
        int key;
        int value;
        node* next;
        node(int k, int v, node* n) : key(k), value(v), next(n) {}
    };
    unordered_map<int, int> kv;
    int size = 0;
    node* head;
public:
    LRUCache(int capacity) {
        size = capacity;
        head = new node(0, 0, NULL);
    }
    
    int get(int key) {
        // 缓存为0的情况
        if (size == 0) return -1;
        if (kv.count(key)) 
        {
            if (size == 1 || kv.size() == 1) return kv[key];
            node* p1 = head;
            node* p2 = head->next;
            while(p2 != NULL && p2->key != key)
            {
                p2 = p2->next;
                p1 = p1->next;
            }
            if (p2 != NULL)
            {
                p1->next = p2->next;
                p2->next = head->next;
                head->next = p2;
                return kv[key];
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        // 缓存为0的情况
        if (size == 0) return;
        // 缓存中存在，则替换key对应的value，同时调整链表
        if (kv.count(key))
        {
            node *p1 = head;
            node *p2 = head->next;
            while (p2 != NULL && p2->key != key) 
            {
                p2 = p2->next;
                p1 = p1->next;
            }
            if (p2 != NULL)
            {
                p2->value = value;
            }
            // 调整链表
            p1->next = p2->next;
            p2->next = head->next;
            head->next = p2;
            // 更新kv
            kv[key] = value;
        }
        // 缓存中不存在，则添加
        else
        {
            if (kv.size() == size) 
            {
                // 缓存已满，先弃置一个，再加入缓存
                // 弃置一组k, v
                node* p = head->next;
                for (int i = 0; i < kv.size() - 1; i++) p = p->next;
                kv.erase(p->key);
                p->next = NULL;
            }
            // 加入缓存
            node* new_node = new node(key, value, head->next);
            head->next = new_node;
            kv[key] = value;
        }
    }
};
```


