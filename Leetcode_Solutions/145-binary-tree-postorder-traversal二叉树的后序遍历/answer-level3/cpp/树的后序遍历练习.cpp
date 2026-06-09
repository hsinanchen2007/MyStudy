### 解题思路

1. 初始两个栈s1,s2
2. 栈s1保存根结点
3. 栈s1弹出p=s1.top()并将p存入栈s2，p->left先入栈s1，p->right再入栈s1
4. 重复步骤3，直至栈s1为空
5. 栈s2按序弹出，并存入在容器res中
6. 重复步骤5，直至栈s2为空
7. 输出容器res

### 代码
```
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        if(root==NULL) return res;

        TreeNode* p=root;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        
        s1.push(p);
        while(!s1.empty())
        {
            p=s1.top();
            s1.pop();
            s2.push(p);
            if(p->left!=NULL) s1.push(p->left);
            if(p->right!=NULL) s1.push(p->right);
        }

        while(!s2.empty())
        {
            p=s2.top();
            s2.pop();
            res.push_back(p->val);
        }
        return res;
    }
};
```