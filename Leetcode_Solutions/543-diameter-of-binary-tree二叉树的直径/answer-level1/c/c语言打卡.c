### 解题思路
递归，最大直径要么为左右子树直径，要么为左右子树深度之和
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

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int treeLenth(struct TreeNode* root, int* depth){
    if(root == NULL){
        *depth = 0;
        return 0;
    }
    else{
        int lDepth, rDepth;
        int lLen = treeLenth(root->left, &lDepth), rLen = treeLenth(root->right, &rDepth);
        *depth = MAX(lDepth, rDepth) + 1;
        int rootDepth = lDepth + rDepth;
        return MAX(MAX(lLen, rLen), rootDepth);
    }
}

int diameterOfBinaryTree(struct TreeNode* root){
    int depth;
    return treeLenth(root, &depth);
}
```