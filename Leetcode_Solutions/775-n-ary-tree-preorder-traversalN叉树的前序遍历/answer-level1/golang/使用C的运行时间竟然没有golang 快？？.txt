### 解题思路
使用C的运行时间竟然没有golang 快？？

### 代码

```c
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

typedef struct Stack {
    struct Node *val;
    struct Stack *next; 
} Stack;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorder(struct Node* root, int* returnSize) {
    int *r = NULL;
    *returnSize = 0;

    if (root == NULL) {
        return r;
    }

    r = malloc(sizeof(int) * 10000);

    Stack *stack = malloc(sizeof(Stack));
    stack->val = root;
    stack->next = NULL;

    for (Stack *v = stack, *s = NULL; v != NULL; s = v->next, free(v), v = s) {

        r[*returnSize] = v->val->val;
        *returnSize = *returnSize + 1;

        Stack *t = v->next;
        Stack *c = v;
        for (int i = 0; i < v->val->numChildren; i++) {
            Stack *s = malloc(sizeof(Stack));
            s->val = v->val->children[i];
            s->next = NULL;
            c->next = s;
            c = c->next;
        }
        c->next = t;
    }

    r = realloc(r, sizeof(int) * (*returnSize));
    return r;
}
```