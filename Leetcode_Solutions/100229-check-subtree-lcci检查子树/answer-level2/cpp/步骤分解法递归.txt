这个题就分解成两个步骤：首先是找子树节点，然后判断是否一致
代码很好理解，才疏学浅，欢迎批评指正```
代码块
**/**
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
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if (t1==NULL || t2==NULL)
            return false;
        TreeNode* newhead = find(t1, t2->val);
        return judge(newhead, t2);
    }

    TreeNode* find(TreeNode* r1, int target)
    {
        TreeNode* res = NULL;
        if (r1!=NULL && r1->val == target)
            res = r1;
        if (res==NULL&&r1!=NULL)
            res = find(r1->left, target);
        if (res==NULL &&r1!=NULL)
            res=find(r1->right, target);
        return res;
    }

    bool judge(TreeNode* r1, TreeNode* r2)
    {
        if (r1==NULL&&r2==NULL)
            return true;
        if (r1==NULL||r2==NULL)
            return false;
        return (r1->val==r2->val)&&judge(r1->left, r2->left)&&judge(r1->right, r2->right);
    }
};**
