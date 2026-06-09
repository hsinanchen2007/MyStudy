第一眼看到这题，我就想用链表，如果用一个数组，存放每个优先级的第一个元素的地址（这样插入就是O(1)），再配上unordered_map，那岂不是完美O(1)，美滋滋，然后就尝试了一下。

```
class LFUCache {
private:
    
    struct Node {
        int key;
        int val;
        int level;
        Node *prev;
        Node *next;
        Node(int k, int v) : key(k), val(v), level(1), prev(nullptr), next(nullptr) {}
    };

    int c;
    bool flag;
    Node *tmp;
    Node *head;
    Node *tail;
    vector<Node *> mylevel;
    unordered_map<int, Node *> m;
    
    void removeChains(Node *a) { // 解除a左右的链
        a->prev->next = a->next;
        a->next->prev = a->prev;
        return;
    }
    
    void push(Node *a, Node *b) { // 把b放到a的next并更新mylevel数组
        a->next->prev = b;
        b->next = a->next;
        a->next = b;
        b->prev = a;
        mylevel[b->level] = b;
        return;
    }
    
    void remove() { // 移除末尾
        tmp = head->next;
        removeChains(tmp);
        if (mylevel[tmp->level] == tmp) mylevel[tmp->level] = nullptr;
        m[tmp->key] = nullptr;
        delete tmp;
        tmp = nullptr;
        return;
    }
    
public:
    
    //mylevel 实测30大小的就够了
    
    LFUCache(int capacity) : mylevel(30), flag(true), c(capacity) {
        if (!capacity) flag = false;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->level = 0;
        tail->level = 0;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!flag) return -1;
        tmp = m[key];
        if (tmp) {
            if (mylevel[tmp->level] == tmp && tmp->level == tmp->prev->level) mylevel[tmp->level] = tmp->prev;
            else if (mylevel[tmp->level] == tmp) {
                mylevel[tmp->level] = nullptr;
                if (!mylevel[tmp->level + 1]) {
                    mylevel[++tmp->level] = tmp;
                    return tmp->val;
                }
            }
            removeChains(tmp);
            ++tmp->level;
            if (!mylevel[tmp->level]) push(mylevel[tmp->level - 1], tmp);
            else push(mylevel[tmp->level], tmp);
            return tmp->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (!flag) return;
        if (get(key) != -1) {
            tmp->val = value;
            return;
        }
        if (--c < 0) remove();
        tmp = new Node(key, value);
        m[key] = tmp;
        if (!mylevel[1]) push(head, tmp);
        else push(mylevel[1], tmp);
        return;
    }
};
```
将链表使用数组模拟，可超过100%，之前的代码是我很久以前写的，实在没耐心重新写了，就直接仿了一遍。
```
const int N=1e4+5;
struct Node{
    int key,val,freq,prev,next;
}pool[N];
int freq[50];
class LFUCache {
private:
    void removeChains(int a){
        pool[pool[a].prev].next=pool[a].next;
        pool[pool[a].next].prev=pool[a].prev;
    }
    void push(int a,int b){
        pool[pool[a].next].prev=b;
        pool[b].next=pool[a].next;
        pool[a].next=b;
        pool[b].prev=a;
        freq[pool[b].freq]=b;
    }
    void remove(){
        tmp=pool[head].next;
        removeChains(tmp);
        if(freq[pool[tmp].freq]==tmp)freq[pool[tmp].freq]=0;
        mp[pool[tmp].key]=0;
        tmp=0;
    }
public:
    int tot=1,head=0,tail=1,cap,tmp;
    bool flag;
    unordered_map<int,int> mp;
    LFUCache(int capacity):cap(capacity){
        flag=cap;
        memset(freq,0,sizeof freq);
        pool[head].next=tail,pool[tail].prev=head;
        pool[head].key=pool[tail].key=pool[head].val=pool[tail].val=-1;
        pool[head].freq=pool[tail].freq=0;
    }
    
    int get(int key) {
        if(!flag)return -1;
        tmp=mp[key];
        if(tmp){
            if(freq[pool[tmp].freq]==tmp&&pool[tmp].freq==pool[pool[tmp].prev].freq){
                freq[pool[tmp].freq]=pool[tmp].prev;
            }else if(freq[pool[tmp].freq]==tmp){
                freq[pool[tmp].freq]=0;
                if(!freq[pool[tmp].freq+1]){
                    freq[++pool[tmp].freq]=tmp;
                    return pool[tmp].val;
                }
            }
            removeChains(tmp);
            ++pool[tmp].freq;
            if(!freq[pool[tmp].freq])push(freq[pool[tmp].freq-1],tmp);
            else push(freq[pool[tmp].freq],tmp);
            return pool[tmp].val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(!flag)return;
        if(~get(key)){
            pool[tmp].val=value;
            return;
        }
        if(--cap<0)remove();
        tmp=++tot;
        pool[tmp].key=key,pool[tmp].val=value,pool[tmp].freq=1,pool[tmp].prev=pool[tmp].next=0;
        mp[key]=tmp;
        if(!freq[1])push(head,tmp);
        else push(freq[1],tmp);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
