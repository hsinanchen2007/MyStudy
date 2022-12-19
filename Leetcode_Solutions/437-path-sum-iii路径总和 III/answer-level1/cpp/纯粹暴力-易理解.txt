### 解题思路
思路看注释

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
    int pathSum(TreeNode* root, int sum) {
        ans = 0;
        if(root == NULL) return 0;
        //把所有节点作为根节点进行计算
        helper(root, sum);
        return ans;
    }
    //纯粹遍历所有节点--先序
    void helper(TreeNode* root, int sum){
        if(root == NULL) return;
        dfs(root, root->val, sum);
        helper(root->left, sum); 
        helper(root->right, sum);
    }
    //以当前节点作为根节点，查找路径
    void dfs(TreeNode* root, int sum,int target){
        if(sum == target) {
            ans++;
        }
        if(root->left != NULL) dfs(root->left, sum + root->left->val, target);
        if(root->right != NULL) dfs(root->right, sum + root->right->val, target);
    }
};
```