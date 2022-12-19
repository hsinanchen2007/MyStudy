## 思路一：递归

## 代码
时间复杂度：O(n)
空间复杂度：O(n)
```c++
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            TreeNode *node = root->left;
            root->left = root->right;
            root->right = node;
            root->left = invertTree(root->left);
            root->right = invertTree(root->right);
        }       
        return root;
    }
}
```

## 思路二：迭代
类似深度优先。
## 代码
时间复杂度：O(n)
空间复杂度：O(n)
```c++
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();            
            TreeNode *tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            q.pop();
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        return root;
    }
};
```
