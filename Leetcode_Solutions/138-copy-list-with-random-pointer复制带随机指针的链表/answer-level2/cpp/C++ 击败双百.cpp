```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr) return nullptr;
    Node* node = head;
    while (node) {
      Node* copy = new Node(node->val);
      copy->next = node->next;
      node->next = copy;
      node = node->next->next;
    }
    node = head;
    Node* copy = node->next;
    while (node) {
      copy = node->next;
      if (node->random != nullptr) {
        copy->random = node->random->next;
      }
      node = node->next->next;
    }
    // split
    Node* new_head = head->next;
    node = head;
    copy = head->next;
    while (node) {
      Node *tmp = copy->next;
      node->next = tmp;
      node = tmp;
      if (node != nullptr) {
        tmp = node->next;
        copy->next = tmp;
        copy = tmp;
      } else {
        copy->next = nullptr;
      }
    }
    return new_head;
  }
};
```