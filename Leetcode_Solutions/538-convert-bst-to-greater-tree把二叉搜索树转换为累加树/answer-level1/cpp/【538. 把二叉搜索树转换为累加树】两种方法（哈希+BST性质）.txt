### 思路一：哈希+遍历
1. 第一次遍历树，将所有节点值存在multiset中
2. 第二次遍历树，在multiset中查找节点值并累加大于节点值的和，然后更新节点

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) return root;
        multiset<int> mset;
        helper(root, mset);
        sumTree(root, mset);
        return root;
    }
    void helper(TreeNode *root, multiset<int> &mset) {
        if (root) {
            mset.insert(root->val);
            helper(root->left, mset);
            helper(root->right, mset);
        }
    }
    void sumTree(TreeNode *root, multiset<int> &mset) {
        if (root) {
            int t = root->val, sum = 0;
            for (auto it = mset.find(t); it != mset.end(); ++it) {
                sum += *it;
            }
            root->val = sum;
            sumTree(root->left, mset);
            sumTree(root->right, mset);
        }
    }
};
```

### 思路二：利用BST性质（最优）
因为二叉搜索树先序遍历为递增序列，所以先右，访问节点，再左即可得到所有大于当前节点值的和。

### 代码
```c++
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root) {
            int sum = 0;
            helper(root, sum);
        }
        return root;
    }
    void helper(TreeNode *root, int &sum) {
        if (root) {
            helper(root->right, sum);
            root->val += sum;
            sum = root->val;
            helper(root->left, sum);
        }
    }
};
```
