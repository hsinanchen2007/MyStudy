### 解题思路
中序遍历到的每个节点 都比上一个节点大 就符合要求了，用一个全局变量记录上一个遍历到的节点值，不需要队列或栈

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

/* 解题思路： 中序遍历到的每个节点 都比上一个节点大 就符合要求了，用一个全局变量记录上一个遍历到的节点值，不需要队列或栈 */
int g_lastval = 0xffffffff;

int dfs(struct TreeNode *root)
{
    if (root == NULL) {
        return 0;
    }

    if ((root->left == NULL) && (root->right == NULL)) {
        if (g_lastval == 0xffffffff) {
            g_lastval = root->val;
            return 0;
        }

        if (root->val <= g_lastval) {
            return -1;
        }

        g_lastval = root->val;
        return 0;
    }

    /* 左子节点 */
    if (dfs(root->left) == -1) {    
        return -1;
    }

    /* 根节点 */
    if ((g_lastval != 0xffffffff) && (root->val <= g_lastval)) {
        return -1;
    }
    g_lastval = root->val;

    /* 右子节点 */
    if (dfs(root->right) == -1) {
        return -1;
    }
    /* 右子节点 先不保存值, 因为该节点 还可能带有 二叉树，需要先确保它的 左子树的最底层叶子节点 大于 该右子节点本身的 根节点 */

    return 0;
}


bool isValidBST(struct TreeNode* root){
    int ret;

    if (root == NULL) {
        return true;
    }

    g_lastval = 0xffffffff;

    ret = dfs(root);
    if (ret == -1) {
        return false;
    }

    return true;
}
```