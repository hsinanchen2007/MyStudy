## 思路一：迭代
注意树为空情况（不过好像没有这个测试案例）
### 代码
```c++
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode *p = new TreeNode(val);
        TreeNode *head = root;
        while (root) {
            if (val < root->val) {
                if (root->left) {
                    root = root->left;
                } else {
                    root->left = p;
                    break;
                }                
            } else if (val > root->val) {
                if (root->right) {
                    root = root->right;
                } else {
                    root->right = p;
                    break;
                }
            }
        }
        return head;        
    }
};
```

## 思路二：递归
### 代码
```c++
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val < root->val) root->left = insertIntoBST(root->left, val);
        else root->right = insertIntoBST(root->right, val);        
        return root;        
    }
};
```

