使用栈，非递归后序遍历二叉树，遇到叶结点时，栈中的结点就是路径
```c
bool hasPathSum(struct TreeNode *root, int sum)
{
    if (!root)
        return false;
    int i, top = -1, s;
    struct TreeNode *p = root;
    struct TreeNode *r = NULL;
    struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode) * 1000);
    while (p || top != -1)
    {
        if (p)
        {
            stack[++top] = p;
            p = p->left;
        }
        else
        {
            p = stack[top];
            if (p->right && p->right != r)
            {
                p = p->right;
                stack[++top] = p;
                p = p->left;
            }
            else
            {
                if (p->left == NULL && p->right == NULL)
                {
                    for (i = 0, s = 0; i <= top; i++)
                        s += stack[i]->val;
                    if (s == sum)
                        return true;
                }
                p = stack[top--];
                r = p;
                p = NULL;
            }
        }
    }
    return false;
}
```
