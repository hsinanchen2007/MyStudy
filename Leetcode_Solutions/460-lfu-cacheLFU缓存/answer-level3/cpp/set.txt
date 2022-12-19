```c++
struct Node{
    int key;
    int val;
    int freq;
    int time;
    Node(int key,int val,int freq,int time){
        this->key = key;
        this->val = val;
        this->freq = freq;
        this->time = time;
    }
};

struct cmp{
    bool operator()(const Node * x,const Node * y) const { 
        if(x->freq == y->freq) return x->time < y->time;
        return x->freq < y->freq;
    }
};

class LFUCache {
public:
    LFUCache(int capacity) {
        this->maxSize = capacity;
        this->timer++;
    }
    
    int get(int key) {
        if(!hash.count(key)) return -1;

        Node * curr = hash[key];
        buffer.erase(curr);
        int ret = curr->val;
        curr->freq++;
        curr->time = this->timer;
        buffer.insert(curr);
        this->timer++;

        return ret;
    }
    
    void put(int key, int value) {
        if(this->maxSize == 0) return;
        if(hash.count(key)){
            Node * curr = this->hash[key];
            buffer.erase(curr);
            curr->val = value;
            curr->freq++;
            curr->time = this->timer;
            buffer.insert(curr);
        }else{
            if(buffer.size() >= this->maxSize){
                Node * curr = *buffer.begin();
                this->hash.erase(curr->key);
                buffer.erase(curr);
            }
            Node * node = new Node(key,value,1,this->timer);
            this->hash[key] = node;
            buffer.insert(node);
        }
        this->timer++;
    }
private:
    unordered_map<int,Node *> hash;
    set<Node*,cmp> buffer;
    int maxSize;
    int timer;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```