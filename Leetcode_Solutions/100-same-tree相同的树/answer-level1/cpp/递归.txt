``` C++
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL) return true;
        if(p==NULL&&q) return false;
        if(q==NULL&&p) return false;
        if(q->val!=p->val)
            return false;
        bool isLeft=isSameTree(p->left,q->left);
        bool isRight=isSameTree(p->right,q->right);
        return isLeft&&isRight;
    }
};
```