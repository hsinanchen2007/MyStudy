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

int maxNum(int a, int b){
    return a>= b ? a : b;
}
int depthNum(struct TreeNode* p, struct TreeNode* q, int depth){
    if(p == NULL && q == NULL){
        return depth;
    }else if(p == NULL && q != NULL){
        ++depth;
        return depthNum(q->left, q->right,depth);
    }else if(p != NULL && q == NULL){
        ++depth;
        return depthNum(p->left, p->right, depth);
    }else{
        ++depth;
        return maxNum(depthNum(p->left, p->right, depth), depthNum(q->left, q->right, depth));
    }
}
int maxDepth(struct TreeNode* root){
    int depth = 0;
    if(root != NULL){
        depth = 1;
        return depthNum(root->left, root->right, depth);
    }
    return 0;
    
}
```