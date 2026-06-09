让dfs返回一个bool值，如果这个值为0就删掉节点，这个值也是一层一层递归上来的，如果下面有1，这个值就不会是0了，如果下面没1了，那就是0了，但是这样的话，如果全是0，那根节点就删不了了，所以最后返回的时候判断一下，如果这个dfs返回结果是0，就直接变空树了。
虽然没有其他评论的方法简洁，不过理解起来也还可以吧
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
    bool dfs(TreeNode *p) {
        if (!p) return 0;
        bool a = dfs(p->left);
        bool b = dfs(p->right);
        if (!a) p->left = nullptr;
        if (!b) p->right = nullptr;
        return p->val || a || b;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root) ? root : nullptr;
    }
};
```
