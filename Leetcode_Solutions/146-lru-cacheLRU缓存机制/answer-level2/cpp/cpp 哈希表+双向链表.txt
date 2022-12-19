哈希表存储key value对，双向链表用于表示某个key最后被使用的时间，从表头到表尾表示key被使用的时间越接近现在。
每次get某个key时，将这个key在双向链表中调整到表尾
`class ListLink{
        public:
            int val;
            ListLink* next;
            ListLink* pre;
            ListLink(int v){
                val=v;
                next=NULL;
                pre=NULL;
            }
           
};
class LRUCache {
    
public:
    int capacity;
    int size;
    map<int,int> m;
    ListLink* head;
    ListLink* tail;
    LRUCache(int capacity) {
        this->capacity=capacity;
        size=0;
        head=new ListLink(0);
        tail=new ListLink(0);
        head->next;tail;
        tail->pre=head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        else{
            ListLink* l=head->next;
            while(l!=tail){
                if(l->val==key)
                    break;
                l=l->next;
            }
            l->pre->next=l->next;
            l->next->pre=l->pre;
            tail->pre->next=l;
            l->pre=tail->pre;
            l->next=tail;
            tail->pre=l;
            return m[key];
        }
            
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            m[key]=value;
            ListLink* l=head->next;
            while(l!=tail){
                if(l->val==key)
                    break;
                l=l->next;
            }
            l->pre->next=l->next;
            l->next->pre=l->pre;
            tail->pre->next=l;
            l->pre=tail->pre;
            l->next=tail;
            tail->pre=l;
            
        }else{
            ListLink* l;
            if(size>=capacity){
                //cout<<key<<" "<<value<<endl;
                l=head->next;
                head->next=l->next;
                head->next->pre=head;
                map<int,int>::iterator it=m.find(l->val);
                m.erase(it);     
                l->val=key;
            }else{
                l=new ListLink(key);
            }
            tail->pre->next=l;
            l->pre=tail->pre;
            l->next=tail;
            tail->pre=l;
            m[key]=value;
            if(size<capacity) size++;
            
        }
        

    }
    
};`