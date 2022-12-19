### 解题思路
给定一个不为空的二叉搜索树和一个目标值 target，请在该二叉搜索树中找到最接近目标值 target 的数值。

注意：

给定的目标值 target 是一个浮点数
题目保证在该二叉搜索树中只会存在一个最接近目标值的数
示例：

输入: root = [4,2,5,1,3]，目标值 target = 3.714286

    4
   / \
  2   5
 / \
1   3

输出: 4




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
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
double dfs(struct TreeNode* root , double target, double max, double min){
    if (root == NULL){
        double a, b;
        a = (max > target) ? (max - target) : (target - max);
        b = (min < target) ? (target - min) : (min - target);
        return a < b ? max : min;
    }
    
    if (target == root->val)
        return root->val;

    else if (root->val < target) {
            min = (min < target ? MAX(root->val, min) : root->val);
            return dfs(root->right, target, max, min);
    }else {
        max = (max > target ? MIN(root->val, max) : root->val);
        return dfs(root->left, target, max, min);
    }
}

int closestValue(struct TreeNode* root, double target){
#if 0
    return dfs(root,target, root->val, root->val);
#else
    double closest = root->val, closestdelta, rootdelta;
    while (root) {
        if(root->val == target)
            return target;
        //这里可以改用fabs函数
        closestdelta = (closest > target) ? (closest - target) : (target - closest);
        rootdelta = (root->val > target) ? (root->val - target) : (target - root->val);
        closest = closestdelta < rootdelta ? closest : root->val;
        
        if (root->val > target)
            root = root->left;
        else
            root = root->right;
    }
    return closest;
#endif
}
```