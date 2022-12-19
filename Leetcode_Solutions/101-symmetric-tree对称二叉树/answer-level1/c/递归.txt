### 解题思路
递归

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


bool chkIsMirror(struct TreeNode* leftNode, struct TreeNode* rightNode)
{
    // 2个节点都为空
    if (leftNode == 0 && rightNode == 0) {
        return true;
    }

    // 2个节点都不能互斥为空
    if (leftNode == 0 && rightNode != 0 || leftNode != 0 && rightNode == 0) {
        return false;
    }

    // 2个节点需要相同
    if (leftNode->val != rightNode->val) {
        return false;
    }

    // 左左孩子和右右孩子，左右孩子和右左孩子都需要相同
    if (chkIsMirror(leftNode->left, rightNode->right) && chkIsMirror(leftNode->right, rightNode->left)) {
        return true;
    }

    return false;
}

bool isSymmetric(struct TreeNode* root) 
{
    if (root == 0) {
        return true;
    } else {
        return chkIsMirror(root->left, root->right);
    }
}
```