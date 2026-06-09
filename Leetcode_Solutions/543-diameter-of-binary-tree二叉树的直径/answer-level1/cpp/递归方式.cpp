### 解题思路

利用递归方式获取每一个节点的左子树的深度和右子树的深度，然后相加得以当前节点为最长距离转折点的时候的长度，与ans比较更新ans，最后比较左右子树的深度来返回当前节点的深度！

### 代码

```cpp
class Solution
{
public:
    int ans;
    int diameterOfBinaryTree(TreeNode *root)
    {
        ans = 0;

        dfs(root);
        return ans;
    }

    int dfs(TreeNode *root)
    {
        if (root)
        {
            int l = dfs(root->left);
            int r = dfs(root->right);
            ans = max(ans, l + r);
            return max(l, r) + 1;
        }
        else
        {
            return 0;
        }
        return -1;
    }
};
```