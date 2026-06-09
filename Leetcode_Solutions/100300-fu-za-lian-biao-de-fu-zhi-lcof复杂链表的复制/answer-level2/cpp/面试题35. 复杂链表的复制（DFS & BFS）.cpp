### DFS
```cpp
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> umap;
        return copyRandomList_helper(umap, head);
    }

    Node* copyRandomList_helper(unordered_map<Node *, Node *> &umap, Node* node) {
        if (node == nullptr) return node;
        auto res = umap.find(node);
        if (res != umap.end()) return res->second;
        Node *newNode = new Node(node->val);
        umap[node] = newNode;
        newNode->next = copyRandomList_helper(umap, node->next);
        newNode->random = copyRandomList_helper(umap, node->random);
        return newNode;
    }
};
```

### BFS
```cpp
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        queue<Node *> quk;
        quk.push(head);
        unordered_map<Node *, Node *> umap;
        Node *newHead = new Node(head->val);
        umap[head] = newHead;
        while (!quk.empty()) {
            Node *cur = quk.front();
            quk.pop();
            if (cur->next != nullptr) {
                auto res = umap.find(cur->next);
                if (res == umap.end()) {
                    quk.push(cur->next);
                    umap[cur->next] = new Node(cur->next->val);
                }
                umap[cur]->next = umap[cur->next];
            }
            if (cur->random != nullptr) {
                auto res = umap.find(cur->random);
                if (res == umap.end()) {
                    quk.push(cur->random);
                    umap[cur->random] = new Node(cur->random->val);
                }
                umap[cur]->random = umap[cur->random];
            }
        }
        return newHead;
    }
};
```