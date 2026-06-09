### 解题思路
二叉搜索树就是节点的左子树只包含小于当前节点的数。节点的右子树只包含大于当前节点的数。所有左子树和右子树自身必须也是二叉搜索树。

我们首先要找到根节点，根节点就是数组最中间的值，如果是奇数就取最中间，偶数我们这里选择取中间靠左的位置，直接（left+right）/2即可，然后左边调用left~mid，右边mid+1~right，递归调用即可。

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

struct TreeNode* helper(int left,int right,int *nums){
    if(left >= right){
        return NULL;
    }
    int midpos = 0;
    midpos = (left+right)/2;
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = nums[midpos];
    node->left = helper(left,midpos,nums);
    node->right = helper(midpos+1,right,nums);

    return node;

}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return helper(0,numsSize,nums);
}
```