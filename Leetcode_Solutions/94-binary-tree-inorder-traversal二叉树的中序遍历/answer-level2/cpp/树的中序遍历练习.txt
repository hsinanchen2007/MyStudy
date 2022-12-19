### 解题思路
中序遍历非递归

### 代码

```

class Solution 
{
public:
    vector<int> inorderTraversal(TreeNode* root)
     {
         TreeNode* p=root;
         vector<int> res;
         stack<TreeNode*> myStack;

         while(!myStack.empty()||p!=NULL)
         {
             while(p!=NULL)
             {
                 myStack.push(p);
                 p=p->left;
             }
             TreeNode* q=myStack.top();
             myStack.pop();
             res.push_back(q->val);
             p=q->right;
         }
         return res;
    }
};
```