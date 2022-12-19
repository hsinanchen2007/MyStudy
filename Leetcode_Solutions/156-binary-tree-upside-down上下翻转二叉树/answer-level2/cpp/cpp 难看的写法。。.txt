![image.png](https://pic.leetcode-cn.com/b7e365da8cc7bff89968f5d3ecf7cb11e31e244395193ab98d415d8c74a5c688-image.png)

居然撸了20多行。。还是太菜了
```
class Solution {
public:
    inline TreeNode* upsideDownBinaryTree(TreeNode* root, TreeNode* prevNode = nullptr) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->left == nullptr) {
            if (prevNode != nullptr) {
                delete root;
                return prevNode;
            } else {
                return root;
            }
        }

        auto node = new TreeNode(root->left->val);
        auto newRoot = root->left;
        node->right = prevNode;
        node->left = root->right;

        if (prevNode != nullptr) {
            delete root;
        } else {
            node->right = root;
            root->right = nullptr;
            root->left = nullptr;
        }

        return upsideDownBinaryTree(newRoot, node);
    }
};
```
