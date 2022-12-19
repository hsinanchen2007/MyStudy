### 解题思路

1. 若根为空，返回最大深度为0；
2. 若根非空，<根，深度为1>入栈；
3. 若左子树非空，访问左子树，<左子树，++深度>入栈；
4. 重复步骤3，直到左子树为空；
5. 记录栈顶的指针和深度，当叶子节点时，更新最小深度；
6. 栈顶元素退栈，访问栈顶元素的右子树；
7. 重复步骤3456，直到栈空且指针为空；         ////若右子树为空，则会跳过步骤34，执行步骤6的退栈。
——————
——————
1. 此题与104题类似；补充一个，当叶子结点时，再比较min与depth；

### 代码

```
class Solution 
{
public:
    int minDepth(TreeNode* root) 
    {
        if(root==NULL) return 0;
        stack<pair<TreeNode*,int>> myStack;
        int depth=0;
        int min=9999;            ///充分大
        TreeNode* p=root;

        while(!myStack.empty()||p!=NULL)
        {
            while(p!=NULL)
            {
                myStack.push(pair<TreeNode*,int>(p,++depth));
                p=p->left;
            }
            p=myStack.top().first;
            depth=myStack.top().second;
            if(p->left==NULL&&p->right==NULL)
            {
                if(min>depth)
                {
                    min=depth;
                }
            }    
            myStack.pop();
            p=p->right;
        }
        return min;
    }
};
```