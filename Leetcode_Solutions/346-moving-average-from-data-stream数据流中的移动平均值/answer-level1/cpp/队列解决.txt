题意大概是想让我们用队列，就自己写个队列，用双链表就好了。
```
struct Node {
    int val;
    Node *next;
    Node *prev;
    Node(int v) : val(v), next(nullptr), prev(nullptr) {}
};

class MovingAverage {
private:
    int capacity;
    int size;
    double sum;
    Node *head;
    Node *tail;
    Node *tmp;
    
    void removeChains(Node *a) {
        a->prev->next = a->next;
        a->next->prev = a->prev;
        return;
    }

    void push(Node *a, Node *b) {
        b->next = a->next;
        b->prev = a;
        a->next = b;
        b->next->prev = b;
        return;
    }
    
    int remove() {
        tmp = tail->prev;
        removeChains(tmp);
        int a = tmp->val;
        delete tmp;
        tmp = nullptr;
        return a;
    }
    
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->sum = 0;
        this->capacity = size;
        this->size = 0;
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }
    
    double next(int val) {
        if (++size > capacity) {
            sum -= remove();
        }
        tmp = new Node(val);
        push(head, tmp);
        sum += val;
        if (size > capacity) return sum / (double)capacity;
        return sum / (double)size;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
```
