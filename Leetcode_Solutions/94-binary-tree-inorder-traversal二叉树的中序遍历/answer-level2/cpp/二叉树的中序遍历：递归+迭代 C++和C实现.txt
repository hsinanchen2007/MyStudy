# **C++写法**

递归：
```
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root,res);
        return res;
    }

    void helper(TreeNode* root,vector<int>& res){
        if(root==NULL)
            return;
        helper(root->left,res);
        res.emplace_back(root->val);
        helper(root->right,res);
    }
};
```
迭代：
```
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while(!s.empty() || p != nullptr)
        {
            if(p != nullptr)
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                TreeNode *t = s.top();
                s.pop();
                res.push_back(t->val);
                p = t->right;
            }
        }
        return res;
    }
};
```
# **C写法**

递归：
```
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int *ar = (int *)malloc(sizeof(int) * 1000);
    inorder(root, ar, returnSize);
    return ar;
}

void inorder(struct TreeNode* root, int *ar, int* returnSize)         // 递归实现        
{
    if(root != NULL)
    {
        inorder(root->left, ar, returnSize);
        ar[(*returnSize)++] = root->val;
        inorder(root->right, ar, returnSize);
    }
}
```

迭代：
```
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* res = (int*)malloc(sizeof(int) * 100),top = -1;
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);
    *returnSize = 0;
    struct TreeNode *p = root;
    while(top != -1 || p != NULL)
    {
        if(p != NULL)
        {
            stack[++top] = p;
            p = p->left;
        }
        else
        {
            p = stack[top--];
            res[(*returnSize)++] = p->val;
            p = p->right;
        }
    }
    return res;
}
```
