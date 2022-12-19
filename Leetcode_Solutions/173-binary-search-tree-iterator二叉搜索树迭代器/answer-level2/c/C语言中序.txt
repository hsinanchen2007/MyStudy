```
typedef struct {
    struct TreeNode**stack;
    int index;
} BSTIterator;

void inorder(struct TreeNode *root,BSTIterator *obj){
    if(root){
        inorder(root->right,obj);
        obj->stack=realloc(obj->stack,sizeof(struct TreeNode*)*(obj->index+2));
        obj->stack[++obj->index]=root;
        inorder(root->left,obj);
    }
}
BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator*obj=malloc(sizeof(*obj));
    obj->index=-1;
    obj->stack=malloc(sizeof(struct TreeNode*));
    inorder(root,obj);
    return obj;
}

/** @return the next smallest number */
int bSTIteratorNext(BSTIterator* obj) {
    if(obj->index>=0){      
        int ret=obj->stack[obj->index]->val;
        obj->index--;
        return ret;
        }
    else return -1;
        
}

/** @return whether we have a next smallest number */
bool bSTIteratorHasNext(BSTIterator* obj) {
    if(obj->index>=0)return true;
    else return false;
}

void bSTIteratorFree(BSTIterator* obj) {
    for(int i=0;i<=obj->index;i++)
        free(obj->stack[i]);
    free(obj);
}
```
