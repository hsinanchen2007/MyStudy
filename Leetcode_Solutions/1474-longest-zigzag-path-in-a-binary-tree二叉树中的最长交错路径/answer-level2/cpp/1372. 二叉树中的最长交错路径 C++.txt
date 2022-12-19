### 解题思路
1.思路：
1）从根节点开始，对每个节点交错取路径
2）**每个子节点都作为根节点，取另外分支的路径**


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
    int left = 0;
    int right = 1;
    int maxlength = 0;

    int dfs(TreeNode *node, int dir)
    {
        if (node == nullptr) {
            return 0;
        }

        int length = 0;
        int otherlength = 0;
        if (dir == right) {
            length = dfs(node->right, left);
            otherlength = dfs(node->right, right);
        } else {
            length = dfs(node->left, right);
            otherlength = dfs(node->left, left);
        }

        maxlength = max(maxlength, max(length+1, otherlength));

        return length + 1;
    }

    int longestZigZag(TreeNode *root)
    {
		maxlength = 0;
        dfs(root, left);
        dfs(root, right);

		return maxlength-1;
    }
};
```