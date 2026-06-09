### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct {
    struct TreeNode *node;
    int flag;
} element;

typedef struct {
    int top;
    int capacity;
    element *val;
} stack;

stack *stack_init(int nsize)
{
    stack *st = (stack *)malloc(sizeof(stack));
    st->top = -1;
    st->capacity = nsize;
    st->val = (element *)malloc(sizeof(element) * nsize);
    return st;
}

element stack_pop(stack *st)
{
    element tmp = st->val[st->top];
    (st->top)--;
    return tmp;
}

int stack_push(stack *st, element n)
{
    if (st->top >= st->capacity - 1) {
        return -1;
    } else {
        (st->top)++;
        st->val[st->top] = n;
        return 1;
    }
}

bool isempty(stack *st)
{
    if (st->top < 0) {
        return true;
    } else {
        return false;
    }
}

void stack_reset(stack *st)
{
    st->top = -1;
}

void stack_destroy(stack *st)
{
    if (st->val != NULL) {
        free(st->val);
    }
    free(st);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int tmp[100];
    int count = 0;
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    stack *st = stack_init(100);
    element tmpele;
    tmpele.node = root;
    tmpele.flag = 0;
    stack_push(st, tmpele);
    while (!isempty(st)) {
        element topnode = stack_pop(st);
        if (((topnode.node)->left == NULL && (topnode.node)->right == NULL) || topnode.flag == 1) {
            tmp[count] = (topnode.node)->val;
            count++;
            continue;
        }
        topnode.flag = 1;
        stack_push(st, topnode);
        if ((topnode.node)->right != NULL) {
            element rightnode;
            rightnode.node = (topnode.node)->right;
            rightnode.flag = -1;
            stack_push(st, rightnode);
        }
        if ((topnode.node)->left != NULL) {
            element leftnode;
            leftnode.node = (topnode.node)->left;
            leftnode.flag = -1;
            stack_push(st, leftnode);
        }
    }
    stack_destroy(st);
    int *result = (int*)malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++) {
        result[i] = tmp[i];
    }
    *returnSize = count;
    return result;
}
```