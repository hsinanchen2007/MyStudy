```
struct Node {
    int val;
    Node *pre, *next;
    Node(int val, Node *pre = nullptr, Node *next = nullptr)
        : val(val), pre(pre), next(next) {}
};
class MyLinkedList {
  public:
    MyLinkedList() : len(0) {
        head = new Node(0);
        tail = new Node(0, head);
        head->next = tail;
    }

    int get(int index) {
        if (index < 0 || index >= len)
            return -1;
        return travel(index)->val;
    }

    void addAtHead(int val) {
        Node *p = new Node(val, head, head->next);
        head->next->pre = p;
        head->next = p;
        len++;
    }

    void addAtTail(int val) {
        Node *p = new Node(val, tail->pre, tail);
        tail->pre->next = p;
        tail->pre = p;
        len++;
    }

    void addAtIndex(int index, int val) {
        if (index > len)
            return;
        if (index == len) {
            addAtTail(val);
            return;
        }
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        Node *p = travel(index);
        Node *n = new Node(val, p->pre, p);
        p->pre->next = n;
        p->pre = n;
        len++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= len)
            return;
        Node *p = travel(index);
        p->pre->next = p->next;
        p->next->pre = p->pre;
        delete p;
        len--;
    }

  private:
    Node *head, *tail;
    int len;
    Node *travel(int index) {
        Node *p;
        if (index < len / 2) {
            p = head;
            for (int i = 0; i <= index; i++, p = p->next)
                ;
        } else {
            p = tail;
            for (int i = 0; i < len - index; i++, p = p->pre)
                ;
        }
        return p;
    }
};
```
