```
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        return helper(head, m);
    }
    Node* helper(Node* head, unordered_map<Node*, Node*>& m) {
        if(!head) return nullptr;
        if(m.count(head)) return m[head];
        Node* p = new Node(head->val);
        m[head] = p;
        p->next = helper(head->next, m);
        p->random = helper(head->random, m);
        return p;
    }
};
```
