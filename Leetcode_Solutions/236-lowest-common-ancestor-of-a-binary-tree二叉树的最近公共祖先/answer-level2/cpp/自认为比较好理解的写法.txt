如果p,q都在左孩子，就去左孩子里面找，如果p,q都在右孩子就去右孩子找，同时记录所有同时包含p,q的节点，然后返回最后一个
```
class Solution {
public:
    bool nodeExistInRoot(TreeNode *root, TreeNode *node) {
        if (root == nullptr) {
            return false;
        }
        if (root == node) {
            return true;
        } else {
            return nodeExistInRoot(root -> left, node) || nodeExistInRoot(root -> right, node);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode *> roots;
        roots.push(root);
        queue<TreeNode *> queue;
        queue.push(root);
        while (roots.size()) {
            TreeNode *r = roots.top();
            roots.pop();
            if (nodeExistInRoot(r -> left, p) && nodeExistInRoot(r -> left, q)) {
                roots.push(r -> left);
                queue.push(r -> left);
            }
            if (nodeExistInRoot(r -> right, p) && nodeExistInRoot(r -> right, q)) {
                roots.push(r -> right);
                queue.push(r -> right);
            }
        }
        return queue.back();
    }
};
```