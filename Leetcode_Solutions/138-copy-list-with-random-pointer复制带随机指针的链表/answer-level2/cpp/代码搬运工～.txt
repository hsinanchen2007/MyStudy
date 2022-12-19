### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Creating a new weaved list of original and copied nodes.
        Node* p = head;
        while (p) {
            // Cloned node
            Node* newNode = new Node(p->val);

            // Inserting the cloned node just next to the original node.
            // If A->B->C is the original linked list,
            // Linked list after weaving cloned nodes would be A->A'->B->B'->C->C'
            newNode->next = p->next;
            p->next = newNode;
            p = newNode->next;
        }

        // Now link the random pointers of the new nodes created.
        // Iterate the newly created list and use the original nodes' random pointers,
        // to assign references to random pointers for cloned nodes.
        p = head;
        while (p) {
            p->next->random = p->random ? p->random->next : nullptr;
            p = p->next->next;
        }

        // Unweave the linked list to get back the original linked list and the cloned list.
        // i.e. A->A'->B->B'->C->C' would be broken to A->B->C and A'->B'->C'
        p = head;
        Node *q = head->next, *newHead = q;
        while (q) {
            p->next = q->next;
            q->next = q->next ? q->next->next : nullptr;
            p = p->next;
            q = q->next;
        }
        return newHead;
    }
};
```