这也不算是easy题了，感觉还是比较绕的，但树的算法题总是离不开dfs，我一直觉得树的题就是套娃题。

如果换个题目，可能就比较容易想到了：找到**从给定的根节点root**开始，连续结点和等于sum的路径的总数。。。那估计大家都是5分钟完事。。。

其实这个题不就是相当于将**从给定的根节点root开始**这个条件，换成了**从任意结点结点开始**吗？那直接外面再套个dfs，前中后序遍历都欧科的。

这样想的话还是蛮简单的，可是如果像我一样，总想往O(N)解，那题目就难了。

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
        if (root == nullptr) return 0;
        return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
        
    }

    int dfs(TreeNode *root, int sum) {
        if (root == nullptr) return 0;
        sum -= root->val;
        if (sum == 0)
            return 1 + dfs(root->left, sum) + dfs(root->right, sum);
        else 
            return dfs(root->left, sum) + dfs(root->right, sum);
    }
};
```
