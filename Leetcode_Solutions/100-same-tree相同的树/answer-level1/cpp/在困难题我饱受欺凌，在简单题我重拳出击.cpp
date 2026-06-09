![image.png](https://pic.leetcode-cn.com/6a7312cc8e408eab1c49ccf1a1855c6758017e64ac5682fb21384feb16a1deff-image.png)
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
    bool check(TreeNode *p,TreeNode *q)
    {
        if(p==NULL&&q!=NULL)
            return false;
        if(p!=NULL&&q==NULL)
            return false;
        if(p==NULL&&q==NULL)
            return true;
        if(p->val!=q->val)
            return false;
        if(check(p->left,q->left)&&check(p->right,q->right))
        {
            return true;
        }
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p,q);
    }
};
```
