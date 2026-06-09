### 解题思路
1. 定义一个变量`sum`记录当前路径的和，变量`ans`记录当前所有路径的和
2. 每进入下一个子树，将当前的`sum*10`再加上该树的`val`
3. 当访问到叶子节点时，将其添加到变量`ans`中

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
    int ans = 0;

    void dfs(TreeNode* root, int sum){
        sum = sum * 10 + root->val;
        if(root->left == NULL && root->right == NULL){
            ans += sum;
        }
        if(root->left) dfs(root->left, sum);
        if(root->right) dfs(root->right, sum);
    }

    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        else dfs(root, 0);
        return ans;
    }
};
```