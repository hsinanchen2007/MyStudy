```
Node* copyRandomList(Node* head) {
    if (head == nullptr) return nullptr;
    for (Node* it = head; it; it = it->next) {
        Node* new_node = new Node(it->val);
        new_node->next = it->next;
        it->next = new_node;
        it = it->next;
    }
    for (Node* it = head; it; it = it->next) {
        Node* new_node = it->next;
        if (it->random) new_node->random = it->random->next;
        it = it->next;
    }
    Node* new_head = head->next;
    for (Node* it = head; it && it->next; it = it->next) {
        Node* new_node = it->next;
        it->next = it->next->next;
        if (new_node->next) new_node->next = new_node->next->next;
    }
    return new_head;
}
```
