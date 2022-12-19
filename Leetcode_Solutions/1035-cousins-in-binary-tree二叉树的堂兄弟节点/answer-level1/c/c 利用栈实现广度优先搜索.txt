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

#define LIMIT 10240

bool isCousins(struct TreeNode* root, int x, int y){
    struct TreeNode* stack[LIMIT] = {NULL};
    struct TreeNode* node = NULL;

    int begin = 0, end = 0, count = 0, i = 0, xflag = 0, yflag = 0;
    stack[end++] = root;
    while(begin != end){
        count = end - begin;
        for(i = 0; i < count; i++){
            node = stack[begin++];
            if(node->left != NULL && node->right != NULL){
                if((node->left->val == x && node->right->val == y) ||
                    (node->left->val == y && node->right->val == x))
                    return false;
            }

            if(node->left != NULL){
                stack[end++] = node->left;
                if(node->left->val == x)
                    xflag = 1;
                else if(node->left->val == y)
                    yflag = 1;
            }
            if(node->right != NULL){
                stack[end++] = node->right;
                if(node->right->val == x)
                    xflag = 1;
                else if(node->right->val == y)
                    yflag = 1;
            }            
        }
        if(xflag == 1 && yflag == 1)
            return true;
        else{
            xflag = 0;
            yflag = 0;
        }
    }
    return false;
}
```