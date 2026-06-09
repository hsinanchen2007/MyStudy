方法一：递归版本


```
class Solution {
public:
    void help(TreeNode* root,vector<int>& res)
    {
        if(root==NULL) return ;
        help(root->left,res);
        res.push_back(root->val);
        help(root->right,res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        help(root,res);
        return res;
    }
};
```


方法二：迭代的方法
```
class Solution {
public:
    //非递归版本就是自己设计一个栈，只要左子树不空或者栈不空，将左子树压入栈中；走到最左边，将栈顶元素输出，将右子树压入栈中，
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;

        auto p=root;
        while(p!=NULL||stk.size())
        {
            while(p)
            {
                stk.push(p);
                p=p->left;
            }
            p=stk.top();
            res.push_back(p->val);
            stk.pop();
            p=p->right;
        }
        return res;
    }
};
```
