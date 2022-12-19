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

#define LEN 1024

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    
    int** arr = (int**)malloc(sizeof(int*) * LEN);
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * LEN);
    // for(int i =0 ; i < LEN ; i++){
    //     returnColumnSizes[i] = (int*)malloc(sizeof(int) );
    //     memset(returnColumnSizes[i] , 0 ,sizeof(int) );
    // }
    if(root == NULL){
        return arr;
    }
    int temp[LEN] = {0};
    int nums = 0;
    recurtive(root, arr, sum , returnSize , returnColumnSizes , temp , nums);

    return arr;
}

void recurtive(struct TreeNode* root, int** arr , int sum , int* returnSize, int** returnColumnSizes , int* temp , int nums){

    if(root == NULL){
        return ;
    }
    if(root->left == NULL && root->right == NULL && sum == root->val){
        temp[nums++] = root ->val;
    
        arr[*returnSize] = (int*)malloc(sizeof(int) * nums);
        for(int i = 0 ; i < nums; i++ ){
            arr[*returnSize][i] = temp[i];
        }
        returnColumnSizes[0][(*returnSize)++] = nums;
        return ;
    }
    temp[nums] = root->val;
    nums++;

    recurtive(root->left, arr, sum - root->val , returnSize , returnColumnSizes , temp , nums);
    recurtive(root->right, arr, sum - root->val , returnSize , returnColumnSizes , temp , nums);
    return ;
}
```