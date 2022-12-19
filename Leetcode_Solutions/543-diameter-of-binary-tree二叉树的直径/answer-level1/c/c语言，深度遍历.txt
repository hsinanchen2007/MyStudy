### 解题思路
1. 深度遍历，带三个出参：当前子树的左树高度a、右树高度b、当前子树的直径c
2. 叶子节点a=b=c=0
3. 非叶子节点递归遍历
- root->left得到左子树的左高度lefta、右高度leftb、直径leftc
- root->right得到左子树的左高度righta、右高度rightb、直径rightc
- 则当前root节点a为fmax(lefta, leftb)+1,b为fmax(righta, rightb)+1,c为(leftc, rightc, a+b)的最大值

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


void calcDepth(struct TreeNode* root, int *leftHeight, int *rightHeight, int *max) {
    if (root->left == NULL && root->right == NULL) {
        *leftHeight = *rightHeight = *max = 0;
        return;
    }

    int tmpL;
    int tmpR;
    int maxL = 0;
    int maxR = 0;

    if (root->left) {
        tmpL = tmpR = 0;
        calcDepth(root->left, &tmpL, &tmpR, &maxL);
        *leftHeight = fmax(tmpL, tmpR) + 1;
    }
    if (root->right) {
        tmpL = tmpR = 0;
        calcDepth(root->right, &tmpL, &tmpR, &maxR);
        *rightHeight = fmax(tmpL, tmpR) + 1;
    }

    *max = fmax(maxL, maxR);
    *max = fmax(*max, *leftHeight+*rightHeight);
    return;
}


int diameterOfBinaryTree(struct TreeNode* root){
    if (!root) return 0;
    int l=0,r=0,m=0;
    calcDepth(root, &l, &r, &m);
    return m;
}
```