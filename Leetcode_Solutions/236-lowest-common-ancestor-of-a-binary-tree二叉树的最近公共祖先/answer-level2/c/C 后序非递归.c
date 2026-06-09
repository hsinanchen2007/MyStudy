利用后序非递归遍历，祖先结点先入栈的特点
关键是标志位

1. 遍历过程中先找到 p 或 q，复制到辅助栈
2. 找到另外一个，从栈底依次比较
```
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (!root || p == root || q == root)
        return root;
    struct TreeNode* stack[20000];
    struct TreeNode* stackhelp[20000];
    int top = -1;
    struct TreeNode *ptr = root, *r = NULL;

    bool flag = false;
    bool flagP = false, flagQ = false;
    while (ptr || top >= 0) {
        if (ptr) {
            stack[++top] = ptr;
            if (flag == false && (ptr == p || ptr == q)) {
                flag = true;
                if (ptr == p)   flagP= true;
                else flagQ = true;
                for (int i = 0; i <= top; ++i) {
                    stackhelp[i] = stack[i];
                    // printf("stackhelp[%d]->%d\n", i, stackhelp[i]->val);
                }
            }
            if (flagQ && ptr == p || flagP && ptr == q) {
                // for (int i = 0; i <= top; ++i)
                //     printf("stack[%d]->%d\n", i, stack[i]->val);
                for (int i = 0; i <= top; ++i)
                    if (stackhelp[i] != stack[i])
                        return stack[i-1];
            }

            ptr = ptr->left;
        } else {
            ptr = stack[top];
            if (ptr->right && ptr->right != r)
                ptr = ptr->right;
            else {
                top--;
                r = ptr;
                ptr = NULL;
            }
        }
    }
    return NULL;
}
```
