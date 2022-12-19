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

int travalTree(struct TreeNode* root, int64_t min, int64_t max)
{
    if (root == NULL) {
        return true;
    }

    int64_t num = root->val;

    if (num <= min || num >= max) { /*比较节点是否在区间内*/
        //printf("return false, (%d,%lld,%lld)\n", num, min, max);
        return false;
    }

    return travalTree(root->left, min, num)  /*左树改变上限为根节点值*/
        && travalTree(root->right, num, max);   /*右树改变下限为根节点值*/
}

bool isValidBST(struct TreeNode* root){
    return travalTree(root, INT64_MIN, INT64_MAX);
}
```