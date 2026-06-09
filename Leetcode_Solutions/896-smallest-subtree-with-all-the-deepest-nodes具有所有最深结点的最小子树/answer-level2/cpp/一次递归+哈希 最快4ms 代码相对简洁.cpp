### 解题思路
题目中特意提到所有节点的值是不重复的，那么可以用节点值作为key构建哈希表，用来储存每个节点的深度。
这样只需一次对所求节点指针的递归就可以了，空间换时间的想法。

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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) { return root; }
        TreeNode *left, *right;
        if(root->left) { left = subtreeWithAllDeepest(root->left); }
        if(root->right) { right = subtreeWithAllDeepest(root->right); }
        
        auto dl = (root->left)? depth[root->left->val]:0, dr = (root->right)? depth[root->right->val]:0;
        depth[root->val] = max(dl,dr)+1;
        
        if(dl==dr) { return root; }
        else { return (dl>dr)? left:right; }
    }

private:
    unordered_map<int,int> depth;
};
```