(1)递归方式：Dfs
```
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root==nullptr) {
            return nullptr;
        }
        TreeNode* tmp = root->left;
        root->left=invertTree(root->right);
        root->right=invertTree(tmp);
        return root;
    }
};
```
(2)非递归方式:Bfs
```
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.top();
            q.pop();
            if (node == nullptr) {
                continue;
            }
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            q.push(node->left);
            q.push(node->right);
        }
    }
};
```

