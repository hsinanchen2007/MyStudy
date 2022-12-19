```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;
        queue<Node*> queue;
        queue.push(root);
        while (!queue.empty()) {
            Node *cur = NULL;
            for (int i = 0, sz = queue.size(); i < sz; ++i) {
                queue.front()->next = cur;
                cur = queue.front();
                if (cur->right != NULL) queue.push(cur->right);
                if (cur->left != NULL) queue.push(cur->left);
                queue.pop();
            }
        }
        return root;
    }
};
```
