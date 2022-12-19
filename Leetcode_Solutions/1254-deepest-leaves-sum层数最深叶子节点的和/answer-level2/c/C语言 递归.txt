### 解题思路
核心思想递归
step1 查找最大深度
step2 按照深度找值求和

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


int depNum(struct TreeNode* root, int nums);
int MaxDepSum(struct TreeNode* root, int sums, int depNum, int curDep);
int max(int a, int b) {
    return (a > b ? a : b);
}

int deepestLeavesSum(struct TreeNode* root){
    int nums = 0;
    int sums = 0;
    nums = depNum(root, nums);
    sums = MaxDepSum(root, sums, nums, 1);
    return sums;
}

/* 返回root的最大深度 */
int depNum(struct TreeNode* root, int nums) {
    if (root == NULL) {
        return nums;
    }

    nums = max(depNum(root->left, nums + 1), depNum(root->right, nums + 1));

    return nums;
}

/* 求所有深度为depNum的合，depNum为需要求和的深度，cur为当前深度 */
int MaxDepSum(struct TreeNode* root, int sums, int depNum, int curDep) {

    if (root == NULL) {
        return 0;
    }

    if (curDep == depNum) {
        return sums + root->val;
    } else {
        return MaxDepSum(root->right, sums, depNum, curDep + 1) + MaxDepSum(root->left, sums, depNum, curDep + 1);
    }
}
```