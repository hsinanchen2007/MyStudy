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
 * Note: The returned array must be malloced, assume caller calls free().
 */
int NodeNum(struct TreeNode* T);
void DFS(struct TreeNode* T,int* returnSize,int* ret,int* i);
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    if(root==NULL) {
        *returnSize=0;
        return NULL;
    }
    
    int num=NodeNum(root);
    int* ret=(int*)calloc(num,sizeof(int));
    *returnSize=0;
    int i=0;
    DFS(root,returnSize,ret,&i);
    return ret;
}

int NodeNum(struct TreeNode* T){
    if(T!=NULL) return NodeNum(T->left)+NodeNum(T->right)+1;
    else return;
}

void DFS(struct TreeNode* T,int* returnSize,int* ret,int* i){
    if(T==NULL) return;
    if(T->left!=NULL) DFS(T->left,returnSize,ret,i);

    (*returnSize)++;
    ret[*i]=T->val;
    (*i)++;

    if(T->right!=NULL) DFS(T->right,returnSize,ret,i);
}









```