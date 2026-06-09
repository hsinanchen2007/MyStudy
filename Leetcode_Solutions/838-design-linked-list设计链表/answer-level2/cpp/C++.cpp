```
class MyLinkedList {

private:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x): val(x), next(nullptr) {}
    };

    ListNode *head;

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new ListNode(0);
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode *p = head;
        while (p && index >= 0) {
            index--;
            p = p->next;
        }
        if (p) {
            return p->val;
        }
        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *node = new ListNode(val);
        node->next = head->next;
        head->next = node;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *node = new ListNode(val);
        ListNode *p = head;
        while (p->next) {
            p = p->next;
        }
        p->next = node;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        ListNode *p = head;
        while (p && index > 0) {
            index--;
            p = p->next;
        }
        if (index > 0) {
            return;
        }
        ListNode *node = new ListNode(val);
        if (p) {
            node->next = p->next;
            p->next = node;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        ListNode *p = head;
        while (p && index > 0) {
            index--;
            p = p->next;
        }

        if (p && p->next) {
            p->next = p->next->next;
        }

    }
};
```
