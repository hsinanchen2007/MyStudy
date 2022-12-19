### 解题思路
1.在左边返回时统计左侧路径的长度。
2.在右侧返回时统计右侧的路径长度。
3.计算路径最大长度并保存。
4.返回左右路径中的最长的。

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

int gMaxTreeLen = 0;
#define MAX(a, b) ((a) > (b) ? (a):(b))
int GetTreeLen(struct TreeNode* root){
    if (root == NULL) {
        return -1;
    }
    int left = GetTreeLen(root->left) + 1;
    int right = GetTreeLen(root->right) + 1;
    //printf("root[%d], left:%d --- right:%d\n", root->val, left, right);
    gMaxTreeLen = MAX(gMaxTreeLen, left + right);
    return MAX(left, right);
}

int diameterOfBinaryTree(struct TreeNode* root){
    gMaxTreeLen = 0;
    GetTreeLen(root);
    return gMaxTreeLen;
}
```