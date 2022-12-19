
```
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* ret = (int*)malloc(1000*sizeof(int));
    struct stack{
        struct TreeNode* a[5000];
        int maxSize;
    };
    struct stack Stack;
    Stack.maxSize = 0;
    int i = 0;
    struct TreeNode* node = root;
    while(Stack.maxSize > 0 || node){
        while(node){
            Stack.a[Stack.maxSize++] = node;
            node = node->left;
        }
        if(Stack.maxSize - 1 >= 0){
            ret[i++] = Stack.a[--Stack.maxSize]->val;
            node = (Stack.a[Stack.maxSize])->right;
        }          
    }
    *returnSize = i;
    return ret;
}
```