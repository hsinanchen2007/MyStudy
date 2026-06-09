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


int maxDepth(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    int nums1 = 1 + maxDepth(root->left);    //算左高度
    int nums2 = 1 + maxDepth(root->right);   //算右高度
    return nums1 > nums2 ? nums1 : nums2;    //返回大值
}
```