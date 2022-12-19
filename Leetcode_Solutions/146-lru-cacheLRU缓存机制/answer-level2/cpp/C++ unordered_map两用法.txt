本方法无需指针，无需内存控制（但速度居然比手撸的链表慢，不懂
```C++
class LRUCache;
class Node {
    int value;
    int pre;//前一个元素的key
    int next;//后一个元素的key
public:
    Node(int value):value(value){};
    Node(){};
    friend LRUCache;
};
class LRUCache {
private:
    unordered_map<int,Node> m;
    int capacity;
    int head;
    int tail;
public:
    LRUCache(int capacity):capacity(capacity) {}
    void to_tail(int key, Node& n){
        if(tail==key)
            return;
        if(head==key)
            head = n.next;
        else
            m[n.pre].next = n.next;
        m[n.next].pre = n.pre;
        m[tail].next = key;
        n.pre = tail;
        tail = key;
    }
    int get(int key) {
        auto a = m.find(key);
        if(a==m.end())
            return -1;
        else {
            Node& n = a->second;
            //将n放到链表末尾
            to_tail(key, n);
            return n.value;
        }
    }
    void put(int key, int value) {
        if(m.find(key)!=m.cend()) {
            Node& n = m[key];
            n.value = value;
            to_tail(key, n);
            return;
        }
        //没找到
        Node node(value);
        const int size = m.size();
        if(size<capacity) {
            if(size==0) {
                m[key] = node;
                head = tail = key;
            }
            else{
                m[tail].next = key;
                node.pre = tail;
                m[key] = node;
                tail = key;
            }
        }
        else {
            //擦除head
            if(capacity==1) {
                m.erase(head);
                m[key] = node;
                head=tail=key;
            }
            else {
                int new_head = m[head].next;
                m.erase(head);
                head = new_head;
                m[tail].next = key;
                node.pre = tail;
                m[key] = node;
                tail = key;
            }
        }
    }
};
```