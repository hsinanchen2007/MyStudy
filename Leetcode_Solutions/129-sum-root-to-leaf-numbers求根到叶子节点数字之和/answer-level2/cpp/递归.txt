### 解题思路
递归


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
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
    void dfs(TreeNode* root, int sum){
        if(root == NULL){
            return;
        }
        sum = sum * 10 + root->val;
        if(root->left == NULL && root->right == NULL){
            ans += sum;
        }
        dfs(root->left, sum);
        dfs(root->right, sum);
    }
};

```