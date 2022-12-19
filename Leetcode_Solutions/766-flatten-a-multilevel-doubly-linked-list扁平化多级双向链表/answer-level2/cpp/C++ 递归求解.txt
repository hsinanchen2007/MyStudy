```
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) {
            return head;
        }
        if (!head->next && !head->child) {
            return head;
        }

        Node *child = flatten(head->child);
        Node *next = flatten(head->next);

        Node *new_head = new Node;
        Node *tail = new_head;
        new_head->prev = NULL;
        new_head->next = NULL;
        new_head->child = NULL;

        tail->next = head;
        head->prev = tail;
        head->child = NULL;
        head->next = NULL;
        tail = head;

        if (child) {
            tail->next = child;
            child->prev = tail;
            child->child = NULL;
            while (tail->next) {
                tail = tail->next;
            }
        }

        if (next) {
            tail->next = next;
            next->prev = tail;
            next->child = NULL;
            while (tail->next) {
                tail = tail->next;
            }
        }

        head = new_head->next;
        head->prev = NULL;
        return head;
    }
};
```
