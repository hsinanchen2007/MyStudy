自己写了一个双向链表结构，每次读写都将这个key对应的node移动到head一端，key和node的对应用hash mpa记录

```cpp
struct DListNode{
    int val;
    int key;
    DListNode *next;
    DListNode *prev;
    DListNode(int v,int k,DListNode *nex=nullptr,DListNode *pre=nullptr)
    {
        val=v;
        key=k;
        next=nex;
        prev=pre;
    }
};
class LRUCache {
private:
    unordered_map<int,DListNode *> cache;
    DListNode *head,*rear;
    int size;
    void deleteNode(DListNode *node)
    {
        DListNode *prev_node=node->prev;
        DListNode *next_node=node->next;
        prev_node->next=next_node;
        next_node->prev=prev_node;
        delete(node);
    }

    void addNode(DListNode *node)
    {
        DListNode *head_next=head->next;
        head->next=node;
        node->prev=head;
        node->next=head_next;
        head_next->prev=node;
    }

    void moveToHead(DListNode *node)
    {
        DListNode *prev_node=node->prev;
        DListNode *next_node=node->next;
        prev_node->next=next_node;
        next_node->prev=prev_node;
        addNode(node);
    }
public:
    LRUCache(int capacity) {
        size=capacity;
        head=new DListNode(0,0,nullptr,nullptr);
        rear=new DListNode(0,0,head,nullptr);
        head->next=rear;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end())
            return -1;
        DListNode *node=cache[key];
        moveToHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(cache.find(key)==cache.end())
        {
            DListNode *node=new DListNode(value,key);
            if(cache.size()==size)
            {
                addNode(node);
                cache[key]=node;
                DListNode *erase_node=rear->prev;
                cache.erase(erase_node->key);
                deleteNode(erase_node);
            }
            else{
            addNode(node);
            cache[key]=node;
            }
        }else{
            DListNode *node=cache[key];
            node->val=value;
            moveToHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 /*
 ["LRUCache","put","put","get","put","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
*/
```