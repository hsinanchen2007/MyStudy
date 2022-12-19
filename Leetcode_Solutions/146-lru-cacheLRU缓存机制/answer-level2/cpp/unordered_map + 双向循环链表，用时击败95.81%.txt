### 代码

```cpp
struct Node {
    int key;
    int value;
    Node *pre;
    Node *next;

    Node(int k, int val) : key(k), value(val), pre(NULL), next(NULL){}
};

class LRUCache {
public:
    LRUCache(int capacity)  : 
        m_capacity(capacity),
        m_size(0),
        m_head(NULL)
    {}
    
    int get(int key) {
        auto iter = m_map.find(key);
        if(iter == m_map.end()){
            return -1;
        }

        Node *node = iter->second;
        if(m_head != node){
            node->pre->next = node->next;
            node->next->pre = node->pre;
            -- m_size;
            push_front(node);
        }

        return node->value;
    }
    
    void put(int key, int value) {
        auto iter = m_map.find(key);
        if(iter != m_map.end()){
            Node *node = iter->second;
            node->value = value;
            if(node != m_head){
                node->pre->next = node->next;
                node->next->pre = node->pre;
                -- m_size;
                push_front(node);
            }

            return;
        }

        Node *newNode = new Node(key, value);
        m_map.insert({key, newNode});
        push_front(newNode);
        if(m_size > m_capacity){
            m_map.erase(pop_back());
        }
    }

private:
    void push_front(Node *node){
        if(m_head == NULL){
            m_head = node;
            m_head->pre = m_head;
            m_head->next = m_head;
        }
        else{
            Node *tail = m_head->pre;
            node->pre = tail;
            node->next = m_head;
            m_head->pre = node;
            tail->next = node;
            m_head = node;
        }

        ++ m_size;
    }

    int pop_back(){
        int rtn;
        if(m_size == 1){
            rtn = m_head->key;
            delete m_head;
            m_head = NULL;
        }
        else{
            Node *tail = m_head->pre;
            tail->pre->next = m_head;
            m_head->pre = tail->pre;
            rtn = tail->key;
            delete tail;
        }

        -- m_size;
        return rtn;
    }

private:
    const int m_capacity;
    int m_size;
    std::unordered_map<int, Node*> m_map;
    Node *m_head;
};
```