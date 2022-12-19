### 解题思路
此处撰写解题思路
（1）如果给定树结点如果为空，则直接返回false；
（2）分别遍历左右子树，如果已经到叶子节点且根节点到叶子结点的和为sum，则返回false；否则返回false；如果左右子树有一个为true，则返回true，否则返回false；

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
bool myHasPathSum(struct TreeNode* root, int sum){
    bool left = false, right = false;

    if (root->left == NULL && root->right == NULL) {
        if (sum - root->val == 0) {
            return true;
        } else {
            return false;
        }
    }
    
    if (root->left) {
        left = myHasPathSum(root->left, sum - root->val);
    }
    if (root->right) {
        right = myHasPathSum(root->right, sum - root->val);
    }

    return left || right;
}

bool hasPathSum(struct TreeNode* root, int sum){
    if (root == NULL) {
        return false;
    }

    return myHasPathSum(root, sum);
}

```

优化一下吧...

### 代码

```c
bool hasPathSum(struct TreeNode* root, int sum){
    if (root == NULL) {
        return false;
    }

    if (root->left == NULL && root->right == NULL) {
        return sum - root->val == 0;
    }

    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}
```