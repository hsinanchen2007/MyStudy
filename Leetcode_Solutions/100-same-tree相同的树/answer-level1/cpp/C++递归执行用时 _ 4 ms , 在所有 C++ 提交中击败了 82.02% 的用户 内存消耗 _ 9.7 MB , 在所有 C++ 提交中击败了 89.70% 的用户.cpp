class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

            if(p&&!q) return false;

            if(!p&&q) return false;

            if(!p&&!q) return true;

            if(isSameTree(p->left,q->left)&&isSameTree(p->right,q->right)&&p->val==q->val) return true;

            return false;
    }
};