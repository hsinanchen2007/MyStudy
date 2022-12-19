### 解题思路
根据二叉搜索树的性质，找第K大相当于向右做中序遍历。

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

#define NOT_FOUND 0xdeadbeef
int num;

int inorderTranverse(struct TreeNode *root, int k, int *retVal) 
{
    int found = 0;
    if (root) {
        found = inorderTranverse(root->right, k, retVal);
        if (found)  //如果找到了，则没必要继续找左子树
            return 1;

        num++;
        if (num == k) { //同上
            *retVal = root->val;
            return 1;
        }
        found = inorderTranverse(root->left, k, retVal);
    }
    return found;
}

int kthLargest(struct TreeNode* root, int k){
    num = 0;
    int retVal, found;
    found = inorderTranverse(root, k, &retVal);
    if (!found)
        retVal = NOT_FOUND;
    return retVal;
}
```