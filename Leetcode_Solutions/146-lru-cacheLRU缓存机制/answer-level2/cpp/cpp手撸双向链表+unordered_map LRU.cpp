
写得好丑-_-
   
    class listnode{
        public:
        listnode (){};
        listnode(int k, int value){
            this->key=k;
            this->val=value;
        };
        int key;
        int val;
        listnode* pre;
        listnode* next;
    };
    
    unordered_map<int,listnode*> h;
    int cap;
    int size;
    listnode* head;
    listnode* tail;
    LRUCache(int capacity) {
        this->cap = capacity;
        this->size=0;
        this->head= new listnode(1,0);
        this->tail= new listnode(1,0);
        head->next=tail;
        tail->pre=head;
    }
    
    int get(int key) {
        if(h.count(key)){
            listnode* node=h[key];
            int value=node->val;
            moveToHead(node,value);
            return value;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(h.count(key)){
            listnode* node = h[key];
            moveToHead(node,value);
        }
        else{
            listnode* node = new listnode(key,value);
            addNodeToHead(node);
            h[key]=node;
            size++;
            if(size>cap){
                removeTail();
                size--;
            }
        }
    }
    
    void moveToHead(listnode *node,int value){
        listnode* move=new listnode(node->key,value);
        addNodeToHead(move);
        node->pre->next=node->next;
        node->next->pre=node->pre;
        //delete(node);
        node=NULL;
        h[move->key]=move;
    }
    
    void addNodeToHead(listnode *node){
        node->pre=head;
        node->next=head->next;
        head->next->pre=node;
        head->next=node;
    }
    
    void removeTail(){
        listnode * pre=tail->pre;
        int k=pre->key;
        listnode *tmp=pre->pre;
        tmp->next=tail;
        tail->pre=tmp;        
        //delete(pre);
        pre=NULL;
        h.erase(k);
    }    
