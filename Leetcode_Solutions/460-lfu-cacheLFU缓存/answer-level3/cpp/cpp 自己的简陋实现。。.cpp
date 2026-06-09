用了双向链表+哈希表

这个版本的get是O（1），但是put操作是O（n）的，因为涉及到删除过期节点时从后向前遍历链表的操作

```
class LFUCache {
public:
    struct listnode{            //链表节点
        listnode* prev;
        listnode* next;
        int _count;             //频次、容量、当前大小、节点key值
        int _cap;
        int _size;
        int _key;
        listnode(){
            prev=nullptr;
            next=nullptr;
            _count=1;
            _cap=0;
            _size=0;
            _key=-1;
        }
    };
    unordered_map<int,pair<int,listnode*>> m;
    listnode* head;
    listnode* tail;
    LFUCache(int capacity) {
        head = new listnode();
        head->_cap = capacity;
        head->_size = 0;
        tail = new listnode();
        tail->_cap = capacity;
        tail->_size = 0;
        head->next=tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.count(key)){
            m[key].second->_count++;
            listnode* tmp = m[key].second;
            move_node_to_head(tmp);        //被访问了，就放到链表头部，表示活跃
            return m[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(head->_cap <= 0)
            return;
        //更新已存在的
        if(m.count(key)){
            m[key].first = value;
            m[key].second->_count++;
            return ;
        }
 
        if(head->_size < head->_cap ){  //值总是正数
            insert_node(key,value);
            head->_size++;
        }
        else if(head->_size == head->_cap ){   //找到最近最少使用的删掉，再加入
            int count = INT_MAX;
            listnode* tmp = nullptr;
            listnode* run = tail->prev;
            int k = -1;
            //找到这个节点
            while(run!=head){
                if(run->_count < count){
                    count = run->_count;
                    tmp = run;
                    k = tmp->_key;
                }
                run = run->prev;
            }
            //删去这个节点
            del_node(tmp);
            tmp = nullptr;
            m.erase(k);
 
            //插入新节点
            insert_node(key,value);
        }
    }
 
    void insert_node(int key, int value){
        listnode* tmp = new listnode();
        head->next->prev = tmp;
        tmp->next = head->next;
        tmp->prev = head;
        head->next = tmp;
        tmp->_key = key;
        m[key] = make_pair(value,tmp);
    }
    void del_node(listnode* tmp){
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        delete tmp;
    }
    void move_node_to_head(listnode* tmp){
        int count = tmp->_count;
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        head->next->prev = tmp;
        tmp->next = head->next;
        head->next = tmp;
        tmp->prev = head;
    }
};
```
