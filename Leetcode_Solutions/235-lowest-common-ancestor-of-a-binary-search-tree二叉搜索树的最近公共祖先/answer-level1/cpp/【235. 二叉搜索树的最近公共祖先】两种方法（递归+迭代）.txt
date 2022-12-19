## 思路一：递归
### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root) {
            if (p->val > root->val && q->val > root->val) {
                return lowestCommonAncestor(root->right, p, q);
            } else if (p->val < root->val && q->val < root->val) {
                return lowestCommonAncestor(root->left, p, q);
            } else {
                return root;
            }
        }
        return root;
    }
};
```

## 思路二：迭代
将思路一递归转为迭代，降低空间复杂度。
### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val > root->val && q->val > root->val) {
                root = root->right;
            } else if (p->val < root->val && q->val < root->val) {
                root = root->left;
            } else {
                return root;
            }
        }
        return root;
    }
};
```

