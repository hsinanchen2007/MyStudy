## 思路一：递归
### 代码
```c++
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root) {
            if (root->val == val) {
                return root;
            } else if (root->val > val) {
                return searchBST(root->left, val);
            } else {
                return searchBST(root->right, val);
            }
        }
        return nullptr;
    }
};
```

## 思路二：迭代
### 代码
```c++
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root) {
            if (root->val == val) {
                return root;
            } else if (root->val > val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return nullptr;
    }
};
```
