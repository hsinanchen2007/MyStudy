### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/bc766028ca1f59be41180bf487b8a20db363e2e19acb7b5bfda24faf3f9a996e-image.png)
很巧妙，直到找到最大的深度，再开始进行计算。后续==该最大深度，才开始累加。前面累加了也无所谓，找到最大深度后，重新赋值
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
int g_maxstep, g_res;

void dfs(struct TreeNode *root, int dep)
{
    if (!root) {
        return;
    }
    //printf("root->val = %d, dep = %d\n", root->val, dep);

    if (dep > g_maxstep) {
        g_maxstep = dep;
        g_res = root->val;
    }
    else if (dep == g_maxstep) {
        g_res += root->val;
    }

    dfs(root->left, dep + 1);
    dfs(root->right, dep + 1);
}

int deepestLeavesSum(struct TreeNode* root){
    g_res = 0;
    g_maxstep = -1;
    dfs(root, 0);

    return g_res;
}
```