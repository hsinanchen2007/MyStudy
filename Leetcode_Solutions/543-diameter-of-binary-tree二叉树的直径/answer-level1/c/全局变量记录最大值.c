### 解题思路

一棵二叉树的直径长度是任意两个结点路径长度中的最大值。

所以我们只需要记录两边深度的和的最大值就好。

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

//记录下每个节点左右深度之和中的最大值
int res=0;

int diameterOfBinaryTree(struct TreeNode* root) {
    res = 0; // 全局变量要清零
    depth(root);
    return res;
}

int depth(struct TreeNode* node) {
    if(node == NULL) return 0;
    int l = depth(node->left);
    int r = depth(node->right);
    res = max(res,l+r);
    return max(l,r)+1;
}
    
int max(int a, int b){ // 返回两个值之间最大的
    if (a > b){
        return a;
    } else {
        return b;
    }
}
```