### 解题思路
两个递归 40ms。仅供参考

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
    bool isSub = false;
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s) return false;
        return isequal(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);
    }
    bool isequal(TreeNode* s, TreeNode* t){
        if(!s && !t) return true;
        if(!s || !t) return false;
        return s->val == t->val && isequal(s->left,t->left) && isequal(s->right,t->right);
    }

};
```