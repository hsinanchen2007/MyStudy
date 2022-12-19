```c++
typedef pair<int,int> pii;

typedef struct Node{
    int key;
    int val;
    int freq;
    Node * next;
    Node * prev;
    Node(){
        this->key = 0;
        this->val = 0;
        this->freq = 1;
        this->next = NULL;
        this->prev = NULL;
    }
}Node;

struct Queue{
    int maxSize;
    int currSize;
    Node * head;
    Queue(int capacity){
        this->maxSize = capacity;
        this->currSize = 0;
        this->head = NULL;
    }
};

bool isEmpty(Queue * qu){
    if(!qu || qu->currSize == 0) return true;
    return false;
}

bool isFull(Queue * qu){
    if(!qu) return true;
    return qu->currSize >= qu->maxSize;
}

bool shiftQueue(Queue * qu,Node * curr){
    if(!qu || !curr) return false;
    if(isEmpty(qu)) return false;
    
    /*shift every node if freq is less or equal than curr*/
    bool replace = false;
    for(Node * node = curr->next; node ; node = curr->next){
        //cout<<"swap :"<<curr->val <<" "<< node->val <<endl;
        /*swap node*/
        if(node->freq <= curr->freq){
            curr->next = node->next;
            node->prev = curr->prev;
            if(curr->prev) curr->prev->next = node;
            if(node->next) node->next->prev = curr;
            curr->prev = node;
            node->next = curr;
            if(qu->head == curr && !replace){
                qu->head = node;
                replace = true;
            } 
        }else{
            break;
        }
    }

    return true;
}

bool pushFront(Queue * qu, Node * node){
    if(!qu||!node) return false;

    if(isEmpty(qu)){
        qu->head = node;
    }else{
        node->next = qu->head;
        qu->head->prev = node;
        qu->head = node;
    }
    qu->currSize++;
    shiftQueue(qu,node);
    return node;
}

int popFront(Queue * qu){
    if(!qu) return false;
    if(qu->currSize == 0 || !qu->head) return false;

    Node * e = qu->head;
    int ret = e->key;
    qu->head = qu->head->next;
    if(qu->head) qu->head->prev = NULL;
    qu->currSize--;
    e->next = NULL;
    e->prev = NULL;
    delete e;

    return ret;
}

bool debugQueue(Queue * qu){
    if(!qu) return false;
    cout<<"curr size = "<<qu->currSize<<endl;
    for(Node * node = qu->head; node; node = node->next){
        cout<<"key:"<<node->key<<" value:"<<node->val<<" freq:"<<node->freq<<endl;
    }
    return true;
}


class LFUCache {
public:
    LFUCache(int capacity) {
        this->qu = new Queue(capacity);
    }
    
    int get(int key) {
        if(!this->hash.count(key)) return -1;

        Node * curr = this->hash[key];
        curr->freq++;
        int ret = curr->val;
        shiftQueue(this->qu,curr);
        return ret;
    }
    
    void put(int key, int value) {
        if(hash.count(key)){
             Node * curr = this->hash[key];
             curr->val = value;
             curr->freq++;
             shiftQueue(this->qu,curr);
        }else{
            /* buffer is full*/
            if(isFull(qu)){
                if(qu->head){
                    this->hash.erase(qu->head->key);
                    popFront(qu);
                }
            }
            if(!isFull(qu)){
                Node * node = new Node();
                node->key = key;
                node->val = value;
                node->freq = 1;
                this->hash[key] = node;
                pushFront(this->qu,node);
            }
        }
    }
private:
    unordered_map<int,Node *> hash;
    Queue *qu;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```