### 解题思路
***思路1：后序遍历***
总体思路：左右节点“富余”或者“缺少”的硬币数汇总到根节点；具体如下：
1、若左节点硬币数为leftNum，若leftNum等于1，则无需移动；若leftNum大于1，则需要向根节点移动（leftNum - 1），对应根节点硬币数变为root->val + （leftNum - 1）；若leftNum等于0，则根节点需要向左节点移动1次，对应根节点硬币数变为root->val  - 1。右节点同理。
故按照这种思路，可以利用二叉树“后序遍历”的思想进行遍历。

2、对应节点需要移动的次数为abs（root->val - 1）；

3、整个二叉树中所有节点需要移动次数为根节点、左节点、右节点移动次数之和。

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

int PostorderTraversal(struct TreeNode* root, int *sum) {

    if ((root == NULL) || (sum == NULL))
        return 0;

    if (root->left != NULL) {
        root->val += PostorderTraversal(root->left, sum);
    }

    if (root->right != NULL) {
        root->val += PostorderTraversal(root->right, sum);
    }
    (*sum) += abs(root->val - 1);
    return (root->val - 1);
}

int distributeCoins(struct TreeNode* root){
    int returnNum = 0;

    if (root == NULL)
        return 0;

    PostorderTraversal(root, &returnNum);

    return returnNum;
}
```