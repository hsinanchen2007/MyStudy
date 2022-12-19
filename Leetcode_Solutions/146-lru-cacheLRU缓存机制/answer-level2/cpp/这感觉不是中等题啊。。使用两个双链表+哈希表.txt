- 第一个保存没用过的节点，第二个双链表保存用过的节点按照访问顺序从左至右排列(最先访问的在最右)，哈希表做缓存
初始化：
- 第一个双链表插入 n 个节点，n 是缓存大小；
- 第二个双链表和哈希表都为空；
- get(key)：
首先用哈希表判断key是否存在：

1. 如果key存在，则返回对应的value，同时将key对应的节点放到第二个双链表的最左侧；
2. 如果key不存在，则返回-1；
- put(key, value)：
1. 首先用哈希表判断key是否存在：
    - 如果key存在，则修改对应的value，同时将key对应的节点放到第二个双链表的最左侧；
    - 如果key不存在：
    1. 如果缓存已满，则删除第二个双链表最右侧的节点（上次使用时间最老的节点），同时将该节点插入第一个双链表的最左端(上次使用时间最早的节点)，更新哈希表；
    2. 否则，插入(key, value)：从第一个双链表中拿出第一个节点，修改节点value，然后将节点从第一个双链表删除，插入第二个双链表最左侧，同时更新哈希表；
- 时间复杂度分析：双链表和哈希表的增删改查操作的时间复杂度都是 O(1)，所以get和set操作的时间复杂度也都是 O(1)。

```cpp
class LRUCache {
public:
    struct Node
    {
        int val, key;
        Node *left, *right;
        Node() : key(0), val(0), left(NULL), right(NULL) {}
    };
    int n;
    Node *hu=new Node(),*tu=new Node(); 
    Node *hr=new Node(),*tr=new Node(); 
    unordered_map<int,Node*>hash;
    LRUCache(int capacity) {
        n = capacity;
        hu->right = tu,tu->left = hu;
        hr->right = tr,tr->left = hr;
        for(int i=0;i<n;i++){
            Node* p = new Node();
            insert_node(hr,p);
        }
    }
    void delete_node(Node *p){
        p->left->right = p->right,p->right->left = p->left;
    }
    void insert_node(Node *h,Node *p){
        p->right = h->right,p->left=h;
        h->right->left = p,h->right=p;
    }
    int get(int key) {
        if(hash[key]){
            Node *p = hash[key];
            delete_node(p);
            insert_node(hu,p);
            return p->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hash[key]){
            Node *p = hash[key];
            delete_node(p);
            insert_node(hu,p);
            p->val = value;
            return;
        }
        if(!n){
            n++;
            Node *p = tu->left;
            hash[p->key] = NULL;
            delete_node(p);
            insert_node(hr,p);
        }
        n--;
        Node *p = hr->right;
        p->key=key,p->val=value;
        hash[key]=p;
        delete_node(p);
        insert_node(hu,p);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```