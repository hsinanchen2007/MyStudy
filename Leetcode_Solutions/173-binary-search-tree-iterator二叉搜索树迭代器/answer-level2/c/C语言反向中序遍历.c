```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



typedef struct {
    int nums[10000];
    int top;
} BSTIterator;

void ReverseInOrder(struct TreeNode *root, BSTIterator *obj)
{
    if (root->right != NULL) {
        ReverseInOrder(root->right, obj);
    }
    obj->nums[++obj->top] = root->val;
    if (root->left != NULL) {
        ReverseInOrder(root->left, obj);
    }
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    BSTIterator *obj = (BSTIterator *)malloc(sizeof(BSTIterator));
    if (obj == NULL) {
        return NULL;
    }
    obj->top = -1;
    ReverseInOrder(root, obj);
    return obj;
}

/** @return the next smallest number */
int bSTIteratorNext(BSTIterator* obj) {
    int num;
    num =  obj->nums[obj->top];
    --obj->top;
    return num;
}

/** @return whether we have a next smallest number */
bool bSTIteratorHasNext(BSTIterator* obj) {
    if (obj == NULL) {
        return false;
    }
    if (obj->top < 0) {
        return false;
    }
    return true;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/
```
