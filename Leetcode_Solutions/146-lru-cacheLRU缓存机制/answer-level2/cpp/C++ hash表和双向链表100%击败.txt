孤陋寡闻没用list，自己写了一个链表结构，相比别人就是多了一些链表的插入删除细节，如果有人也是自己写的话可以看一下。

```cpp
class LRUCache {
    struct ListNode{
        int key;
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int k, int v):key(k), val(v), next(NULL), prev(NULL){}
    };
private:
    unordered_map<int, ListNode*> m;
    int maxCap;
    ListNode* head=new ListNode(0,0);
    ListNode* tail=new ListNode(0,0);
    int cur=0;
public:
    LRUCache(int capacity):maxCap(capacity){
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end())
            return -1;
        ListNode* temp=m[key];
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;

        tail->prev->next=temp;
        temp->next=tail;
        temp->prev=tail->prev;
        tail->prev=temp;
        return m[key]->val;
        
    }
    
    void put(int key, int value) {
        if(maxCap==0)   return;

        if(m.find(key)!=m.end()){
            get(key);
            m[key]->val=value;
            return;
        }

        ListNode* temp = new ListNode(key, value);
        if(cur==maxCap){
            ListNode* t=head->next;        
            head->next->next->prev=head;
            head->next=head->next->next;
            m.erase(t->key);
            delete t;
            cur--;      
        }
        cur++;
        m[key]=temp;
        
        tail->prev->next=temp;
        temp->next=tail;
        temp->prev=tail->prev;
        tail->prev=temp;
    }
};


```