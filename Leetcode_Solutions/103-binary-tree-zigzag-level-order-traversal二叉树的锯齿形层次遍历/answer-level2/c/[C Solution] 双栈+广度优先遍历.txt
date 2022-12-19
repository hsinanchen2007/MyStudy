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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX 1024

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){

    int ** arr = (int**)malloc(sizeof(int*) * MAX);
    *returnColumnSizes = (int*)malloc(sizeof(int) * MAX);
    *returnSize = 0;

    if(root == NULL){
        return arr;
    }

    struct TreeNode** l2rArr = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * MAX);
    struct TreeNode** r2lArr = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * MAX);
    int l2rLen = 0, r2lLen = 0;

    l2rArr[l2rLen++] = root;

    bool left2right = true;

    while(l2rLen != 0 || r2lLen != 0){
        if(left2right){
            arr[*returnSize] = (int*)malloc(sizeof(int)*l2rLen);
            returnColumnSizes[0][(*returnSize)] = l2rLen;
            int l2rIdx = 0 ;

            while(l2rLen > 0){
                struct TreeNode* tmp = l2rArr[l2rLen -1];
                arr[*returnSize][l2rIdx] = tmp->val;

                if(tmp->left != NULL){
                    r2lArr[r2lLen++] = tmp->left;
                }
                if(tmp->right != NULL){
                    r2lArr[r2lLen++] = tmp->right;
                }
                l2rIdx++;
                l2rLen--;
            }
            (*returnSize)++;
            left2right = !left2right;
        }else{
            arr[*returnSize] = (int*)malloc(sizeof(int)*r2lLen);
            returnColumnSizes[0][*returnSize] = r2lLen;
            int r2lIdx = 0;

            while(r2lLen > 0){
                struct TreeNode* tmp = r2lArr[r2lLen - 1 ];
                arr[*returnSize][r2lIdx++] = tmp->val;
                
                if(tmp->right != NULL){ 
                    l2rArr[l2rLen++] = tmp->right;
                }
                if(tmp->left != NULL){
                    l2rArr[l2rLen++] = tmp->left;
                }
                r2lLen--;
            }
            (*returnSize)++;
            left2right = !left2right;
        } 
    }

    return arr;
}
```