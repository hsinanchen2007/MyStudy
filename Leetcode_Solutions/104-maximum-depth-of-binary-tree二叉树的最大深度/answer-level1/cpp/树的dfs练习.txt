### 解题思路

    1. 若根为空，返回最大深度为0；
    2. 若根非空，<根，深度为1>入栈；
    3. 若左子树非空，访问左子树，<左子树，++深度>入栈；
    4. 重复步骤3，直到左子树为空；
    5. 记录栈顶的指针和深度，并更新最大深度；
    6. 栈顶元素退栈，访问栈顶元素的右子树；
    7. 重复步骤3456，直到栈空且指针为空；         ////若右子树为空，则会跳过步骤34，执行步骤6的退栈。

### 代码

```
class Solution 
{
public:
    int maxDepth(TreeNode* root) 
    {
        if(root==NULL)return 0;
        int depth=0;
        int max=0;
        stack<pair<TreeNode*,int>> myStack;
        TreeNode*p=root;
        
        while(!myStack.empty()||p!=NULL)
        {
            while(p!=NULL)
            {
                myStack.push(pair<TreeNode*,int>(p,++depth));
                p=p->left;
            }
            p=myStack.top().first;
            depth=myStack.top().second;
            if(max<depth) max=depth;
            myStack.pop();
            p=p->right;
        }
        return max;

        
    }
};
```