- 先找右子树，再比较根结点，最后找左子树
- cnt用于计数，找到了就返回结点值，没找到就返回-1

```
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
    int cnt = 0;
    int kthLargest(TreeNode* root, int k) {
        if (root) {
            int node1 = kthLargest(root->right, k);
            if (node1 != -1) return node1;
            cnt++;
            if (cnt == k) return root->val;
            int node2 = kthLargest(root->left, k);
            if (node2 != -1) return node2;
        }
        return -1;
    }
};
```
