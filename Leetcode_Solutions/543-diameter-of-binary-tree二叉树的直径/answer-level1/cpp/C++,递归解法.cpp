### 解题思路
C++,递归解法，树的宽度为以某一结点为根节点的最长左子树深度加最长右子树深度
帮助函数在求以某结点ge为根的最大深度的同时，更新以此节点g为根的宽度是否超过当前最大。

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
private:
    int ans;
    int helper(TreeNode* root){
        //返回以root为根节点的树的最大深度
        if(!root) return 0;
        int ltree = helper(root->left);
        int rtree = helper(root->right);

        ans = max(ans, ltree + rtree);

        return max(ltree, rtree) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        helper(root);

        return ans;
    }
};
```