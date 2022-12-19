利用2个栈，1个左子节点优先进入，1个右子节点优先进入，左优先栈弹出时，弹出的节点的右子节点优先入右优先栈，左子节点后入右优先栈，反之，当右优先栈弹出时，弹出的节点的左子节点优先入左优先栈，右子节点后入左优先栈，反复操作直到2个栈均为空。
在此期间，弹每个栈时，创建一个数组保存节点值和数量，挂在**result指针对应行处即可。
代码有点长，个人水平不佳。
```
typedef struct node {
    int val;
    struct TreeNode *root;
} NODE;
NODE leftFirstStack[5000];  /* 左子节点优先入栈 */
NODE rightFirstStack[5000]; /* 右子节点优先入栈 */
int lTop, rTop;
void Push(NODE *stack, int top, NODE *node)
{
    stack[top].val = node->val;
    stack[top].root = node->root;
}
void Pop(NODE *stack, int top, NODE *node)
{
    node->val = stack[top - 1].val;
    node->root = stack[top - 1].root;
}
void Init()
{
    lTop = 0;
    rTop = 0;
}
void PushStack(struct TreeNode* root, NODE *stack, int *top)
{
    NODE next;
    if (root != NULL) {
        next.val = root->val;
        next.root = root;
        Push(stack, *top, &next);
        (*top)++;
    }
}
void PopLeftStack(int *p, int *cnt)
{
    NODE node;
    int index = lTop;
    *cnt = 0;
    while (lTop > 0) {
        Pop(leftFirstStack, lTop, &node);
        p[index - lTop] = node.val;
        lTop--;
        (*cnt)++;
        PushStack(node.root->right, rightFirstStack, &rTop);
        PushStack(node.root->left,  rightFirstStack, &rTop);
    }
}
void PopRightStack(int *p, int *cnt)
{
    NODE node;
    int index = rTop;
    *cnt = 0;
    while (rTop > 0) {
        Pop(rightFirstStack, rTop, &node);
        p[index - rTop] = node.val;
        rTop--;
        (*cnt)++;
        PushStack(node.root->left,  leftFirstStack, &lTop);
        PushStack(node.root->right, leftFirstStack, &lTop);
    }
}
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **result, *p, *cnt;
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    Init();
    PushStack(root, rightFirstStack, &rTop);
    result = calloc(3000, sizeof(int*));
    cnt = calloc(3000, sizeof(int));
    while ((lTop > 0) || (rTop > 0)) {
        if (lTop > 0) {
            p = calloc(lTop, sizeof(int));
            PopLeftStack(p, &cnt[*returnSize]);
            result[*returnSize] = p;
            (*returnSize)++;
        }
        if (rTop > 0) {
            p = calloc(rTop, sizeof(int));
            PopRightStack(p, &cnt[*returnSize]);
            result[*returnSize] = p;
            (*returnSize)++;
        }
    }
    *returnColumnSizes = cnt;
    return result;
}
```
