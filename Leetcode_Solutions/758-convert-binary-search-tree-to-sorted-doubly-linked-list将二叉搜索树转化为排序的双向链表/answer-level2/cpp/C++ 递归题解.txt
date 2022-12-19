```C++ []
class Solution {
public:
    Node* dfs(Node* root) {
        if (root == NULL) return NULL;
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        if (l == NULL) {
            Node* head = root;
            head->right = r;
            if (r) r->left = head;
            return head;
        }
        Node* head = l;
        while (l != NULL && l->right != NULL) {
            l = l->right;
        }
        l->right = root;
        root->left = l;
        root->right = r;
        if (r) r->left = root;
        return head;
    }
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) return NULL;
        Node* head = dfs(root);
        Node* node = head;
        while (node != NULL && node->right != NULL) {
            node = node->right;
        }
        node->right = head;
        head->left = node;
        return head;
    }
};
```

![image.png](https://pic.leetcode-cn.com/1778b48661f2c63c0c0a94844c454bde76997dd86d38661683012040a523afa3-image.png)
