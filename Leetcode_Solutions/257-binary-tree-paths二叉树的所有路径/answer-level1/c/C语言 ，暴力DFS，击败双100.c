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
#define MAX 1000
struct Path{
    struct TreeNode *node;
    char path[MAX];
};
char * getNewPath(char* odd, int val){
    char *res = (char*)malloc(sizeof(char)*(strlen(odd)+10)), temp[10];
    strcpy(res, odd);
    sprintf(temp, "%d", val);
    strcat(res, "->");
    strcat(res, temp);
    return res;
}
char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    struct Path **stack = (struct Path **) malloc (sizeof(struct Path*) * 1000);
    char **res = (char**) malloc (sizeof(char*) * 1000), r[10];
    if(root==NULL){
        *returnSize = 0;
        return NULL;
    }
    int top = 0, resIndex = 0;
    stack[top] = (struct Path *)malloc(sizeof(struct Path));
    stack[top]->node = root;
    sprintf(r, "%d", root->val);
    strcpy(stack[top]->path, r);
    while(top >= 0){
        struct Path *curr = stack[top--];
        // find a leaf
        if(curr->node->left==NULL && curr->node->right==NULL){
            res[resIndex] = (char *)malloc(sizeof(char) * (strlen(curr->path)+2));
            strcpy(res[resIndex++], curr->path);
        }
        if(curr->node->right != NULL){
            stack[++top] = (struct Path *)malloc(sizeof(struct Path));
            stack[top]->node = curr->node->right;
            strcpy(stack[top]->path,getNewPath(curr->path, curr->node->right->val));
        }
        if(curr->node->left != NULL){
            stack[++top] = (struct Path *)malloc(sizeof(struct Path));
            stack[top]->node = curr->node->left;
            strcpy(stack[top]->path,getNewPath(curr->path, curr->node->left->val));
        }
    }
    *returnSize = resIndex;
    return res;
}
```