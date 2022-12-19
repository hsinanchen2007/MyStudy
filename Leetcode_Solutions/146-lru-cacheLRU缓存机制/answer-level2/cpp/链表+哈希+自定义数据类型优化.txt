为了实现put，get在O(1)完成，则必须使用哈希；
又要随时更新每一次操作，使得当前节点更新为最新访问节点，则可以使用双向链表。
java可以使用有序哈希（LinkedHashMap），但c++只好用list+hashmap。
```
class LRUCache {
    int capacity;
    list<pair<int,int> > lrulist;
    unordered_map<int,list<pair<int,int> >::iterator> cache;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        lrulist.clear();
        cache.clear();
    }
    
    int get(int key) {
        const auto &f = cache.find(key);
        if(f==cache.end()) return -1;
        int val = f->second->second;
        lrulist.erase(f->second);
        lrulist.push_front(make_pair(key,val));
        cache[key] = lrulist.begin();
        return val;
    }
    
    void put(int key, int value) {
        const auto &f = cache.find(key);
        if(f==cache.end()){
            if(capacity==cache.size()){
                cache.erase(lrulist.back().first);
                lrulist.pop_back();
            }
        }
        else lrulist.erase(f->second);
        lrulist.push_front(make_pair(key,value));
        cache[key]=lrulist.begin();
    }
};
```
由于每次get都要更新访问节点，使其作为最新节点，list不支持move to front操作，只能先删除，在添加。可以自定义list，实现仅节点移动，省去创建和销毁的消耗。
```
// Time 120ms, 96.4%, Space 38MB, 84.8%
class LRUCache {
    struct ListNode{
        int key, val;
        ListNode *next, *prev;
        ListNode(int k, int v):key(k),val(v),next(NULL),prev(NULL){}
    };
    class LRUList{
        int size;
        ListNode *front, *tail;
    public:
        typedef ListNode* iterator;
        LRUList(){
            size=0;
            front=tail=NULL;
        }
        ~LRUList(){
            clear();
        }
        void clear(){
            size=0;
            for(; front;){
                tail=front;
                front=front->next;
                delete tail;
            }
            front=tail=NULL;
        }
        iterator begin(){
            return front;
        }
        ListNode& back(){
            return *tail;
        }
        void erase(iterator node){
            if(node->prev) node->prev->next=node->next;
            if(node->next) node->next->prev=node->prev;
            if(node==front) front=node->next;
            if(node==tail) tail=node->prev;
            --size;
        }
        void push_front(const ListNode &rnode){
            iterator node = new ListNode(rnode.key,rnode.val);
            if(front){
                front->prev=node;
                node->next=front;
            }
            else tail=node;
            front=node;
            ++size;
        }
        void pop_back(){
            if(!tail) return;
            if(front==tail){
                delete front;
                front=tail=NULL;
            }
            else{
                tail=tail->prev;
                delete tail->next;
                tail->next=NULL;
            }
            --size;
        }
        void move_front(iterator node){
            if(front==node) return;
            node->prev->next=node->next;
            if(node->next) node->next->prev=node->prev;
            if(node==tail) tail=node->prev;
            node->next=front;
            node->prev=NULL;
            front=front->prev=node;
        }
    };

    int capacity;
    LRUList lrulist;
    unordered_map<int,LRUList::iterator> cache;
    //list<ListNode> lrulist;
    //unordered_map<int,list<ListNode>::iterator> cache;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        lrulist.clear();
        cache.clear();
    }

    int get(int key) {
        const auto &f=cache.find(key);
        if(f==cache.end()) return -1;
        int val=f->second->val;
        //lrulist.erase(f->second);
        //lrulist.push_front(ListNode(key,val));
        lrulist.move_front(f->second);
        cache[key]=lrulist.begin();
        return val;
    }
    
    void put(int key, int value) {
        const auto &f=cache.find(key);
        if(f==cache.end()){
            if(capacity==cache.size()){
                cache.erase(lrulist.back().key);
                lrulist.pop_back();
            }
            lrulist.push_front(ListNode(key,value));
        }
        else {
            //lrulist.erase(f->second);
            //lrulist.push_front(ListNode(key,value));
            f->second->val=value;
            lrulist.move_front(f->second);
        }
        cache[key]=lrulist.begin();
    }

};
```
