

```
int top;
int findSecondMinimumValue(struct TreeNode* root){
    int *value = (int *)calloc(1024, sizeof(int));
    top = 0;
    find_node(value, root);
    unsigned int fir_min = 0xffffffff;
    unsigned int sec_min = 0xffffffff;
    for (int i = 0; i < top; ++i) {
        if (value[i] <= fir_min)     fir_min = value[i];
        else if (value[i] < sec_min) sec_min = value[i];
    }

    return (0xffffffff == sec_min ? -1 : sec_min);
}

int find_node(int value[], struct TreeNode* root)
{
    if (root == NULL) return 0;
    value[top++] = root->val;
    find_node(value, root->left);
    find_node(value, root->right);
    return 0;
}
```
