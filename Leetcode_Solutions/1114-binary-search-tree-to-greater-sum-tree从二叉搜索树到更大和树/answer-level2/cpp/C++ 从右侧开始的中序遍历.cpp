### 解题思路
从右侧开始中序遍历，不断累加节点值即可

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
    void dfs(TreeNode* root, int& sum) {
        if (root == NULL) return;
        dfs(root->right, sum);
        root->val += sum;
        sum = root->val;
        dfs(root->left, sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return root;
    }
};
```

![image.png](https://pic.leetcode-cn.com/29343fecf58161678cb6aeeca219f8424d7a837408694f7901e0fd2b16b5d3b5-image.png)
