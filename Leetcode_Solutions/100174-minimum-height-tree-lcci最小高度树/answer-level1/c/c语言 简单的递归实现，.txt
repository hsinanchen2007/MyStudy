### 解题思路
递归实现，每次获取中间点的值，加入到树种；
注意细节：1.mid的计算需要left + （right - left + 1）/2；
2.退出条件

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
struct TreeNode* getMid(int *nums,int numsSize, int left, int right) {
   // printf("numsize %d, left %d, right %d\n",numsSize, left, right);

    int mid = left + (right - left + 1) / 2;
    struct TreeNode *tmp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tmp->val = nums[mid];
    if (mid - 1 >= 0 && left <= mid - 1)
        tmp->left = getMid(nums, numsSize,left,mid - 1);
    else
        tmp->left = NULL;

    if (mid + 1 < numsSize && mid + 1 <= right)
        tmp->right = getMid(nums, numsSize, mid + 1, right);
    else
        tmp->right = NULL;
    return tmp;
    

}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if (numsSize == 0)
        return NULL;
    
    return getMid(nums,numsSize,0,numsSize - 1);
}
```