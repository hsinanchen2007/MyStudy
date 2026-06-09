使用队列对二叉树进程层序遍历
非递归，好理解
```
int rangeSumBST(TreeNode* root, int L, int R) {
    int res=0;
    queue<TreeNode*> q;
    q.push(root);
    while(q.size())
    {
        TreeNode *p=q.front();
        if (p->val>=L &&p->val<=R ) 
        {
            res+=p->val;
        }
        q.pop();
        if (p->left) 
        {
            q.push(p->left);
        }
        if (p->right)
        {
            q.push(p->right);
        }
    }
    return res;
    }
```
执行用时 :
136 ms
, 在所有 cpp 提交中击败了
98.69%
的用户
内存消耗 :
43.5 MB
, 在所有 cpp 提交中击败了
7.81%
的用户

