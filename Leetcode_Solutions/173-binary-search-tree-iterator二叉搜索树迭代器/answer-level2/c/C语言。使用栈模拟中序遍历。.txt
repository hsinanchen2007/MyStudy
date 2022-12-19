```
typedef struct {
    struct TreeNode* stack[256];
    int top;
} BSTIterator;


BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* obj = (BSTIterator*)malloc(sizeof(BSTIterator));
    obj->top = 0;
    while(root){
        obj->stack[obj->top++] = root;
        root = root->left;
    }
    return obj;
}

int bSTIteratorNext(BSTIterator* obj) {
    struct TreeNode* root = obj->stack[--obj->top];
    int val = root->val;
    root = root->right;
    while(root){
        obj->stack[obj->top++] = root;
        root = root->left;
    }
    return val;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->top > 0;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj);
}
```
