这种题一看就会一写就完该怎么办，想想自己为啥写不出呢？1、那个结构体挺唬人的，2、要尝试分开写功能函数
```
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return ismirror(root->right,root->left);

    }

    bool ismirror(TreeNode* p,TreeNode* q)
    {
    if(!p&&!q) return true;
    if(!p||!q) return false;
    return (p->val==q->val)&&ismirror(p->right,q->left)&&ismirror(p->left,q->right);
    }
};
```
