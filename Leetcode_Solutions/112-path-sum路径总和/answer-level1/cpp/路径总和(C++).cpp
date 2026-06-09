### 解题思路
此处撰写解题思路
这道题目一看用dfs就很容易解决。
- 记住dfs几种常见的格式这里的if-else就是一种;
- 只要有一条路径满足条件就可以，所以bool类型返回用了或(||);
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
    bool hasPathSum(TreeNode* root, int sum) {
        return valid(root, sum, 0);
    }

    bool valid(TreeNode* root, int sum, int path) {
        if (!root){

            return false;
        }
        else {
            path += root->val;
            if (root->left == nullptr && root->right == nullptr && sum == path)
                return true;
            
            return valid(root->left, sum, path) || valid(root->right, sum, path);
        }
    }
};
```