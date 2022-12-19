### 解题思路
我们首先要实现一个利用深度优先遍历，求某个根节点开始的子树的所有符合要求的路径总数的函数dfs；然后每次递归就是求以某个根节点开始的dfs返回的路径数目+递归调用左孩子的返回值+递归调用右孩子的返回值。

因为路径可以不从根节点开始，也可以不到叶子结点结束。
对于从根节点开始到叶子节点结束的情况，只需要调用递归函数求从根节点到各个叶子节点的和是否等于目标值即可，但是对于本题需要**先递归将每一个节点作为起始点**，然后**再从该节点递归求解从其开始各个路径之和**，当到达根节点或者节点值之和等于目标值的时候结束该节点的递归函数。

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(NULL == root)
            return 0;
        return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int dfs(TreeNode* T, int sum)
    {
        //深度优先遍历，搜索某子树的所有可能路径
        int res = 0;
        if(T == NULL)
            return res;//节点为空时返回0
        if(sum == T->val)
            res++;//此时说明到该节点的路径是符合要求的
        res += dfs(T->left, sum - T->val);//目前的路径数目+遍历左子树得到的路径数目；
        res += dfs(T->right, sum - T->val);
        return res;
    }

};
```