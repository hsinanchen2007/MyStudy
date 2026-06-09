方法一：递归版本


```
class Solution {
public:
    bool bst(TreeNode* p,TreeNode* q)
    {
        if(p==NULL&&q==NULL) return true;
        if(p==NULL||q==NULL) return false;
        return p->val==q->val&&bst(p->left,q->right)&&bst(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return bst(root->left,root->right);
    }
};
```


方法二：迭代版本
```
class Solution {
public:
    //和二叉树中序遍历的迭代方法有点类似，左子树是按照左中右遍历，分别压入栈中，右子树是按照右中左的顺序遍历，也是分别压入栈中判断，分别判断值是否相等
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        stack<TreeNode*> left,right;


        TreeNode* l=root->left;
        TreeNode* r=root->right;

        while(l||r||left.size()||right.size())
        {
            while(l&&r)//这里是同时存在的时候
            {
                left.push(l);
                l=l->left;
                right.push(r);
                r=r->right;
            }
            if(l||r) return false;//这里多判断一步，如果一个为空一个不为空，直接返回

            l=left.top();left.pop();
            r=right.top();right.pop();
            
            if(l->val!=r->val) return false;

            l=l->right;r=r->left; 

        }
        return true;
    }
};
```

