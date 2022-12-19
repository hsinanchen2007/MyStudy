因为这道题地两个二维数组把我给难住了，借鉴了一下一位网友在题解里的解法

```
int* preorder(struct Node* root, int* returnSize) {
    *returnSize = 0;
    if (!root)
    {
        return NULL;
    }
    struct Node **stack = (struct Node**)malloc(sizeof(struct Node) * 10240);
    int *arr = (int*)malloc(sizeof(int) * 10240);
    int top = -1;
    stack[++top] = root;
    while(top != -1)
    {
        struct Node *tmp = stack[top--];
        arr[(*returnSize)++] = tmp->val;

        for(int i = tmp->numChildren - 1; i >= 0 ; i--)
        {
            stack[++top] = tmp->children[i];
        }
    }
    return arr;
}
```