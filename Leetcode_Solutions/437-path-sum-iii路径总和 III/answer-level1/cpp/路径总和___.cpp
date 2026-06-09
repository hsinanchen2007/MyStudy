### 解题思路
深度优先搜索，递归遍历左右子树

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
    int cnt;
    void dfs(TreeNode* root, int curSum, int sum){//以root为根节点进行深度搜索
        if(!root){
            return ;
        }
        curSum += root->val;//加上当前节点
        if(curSum==sum){
            cnt++;
        }
        dfs(root->left, curSum, sum);
        dfs(root->right, curSum, sum);
        curSum -= root->val; 
    }
    void PathSum(TreeNode* root, int sum){
        if(!root)
            return;
        dfs(root, 0, sum);
        PathSum(root->left, sum);//以左孩子为根，进行dfs
        PathSum(root->right, sum);//以右孩子为根，进行dfs
    }
    int pathSum(TreeNode* root, int sum) {
        //int cnt = 0;
        PathSum(root, sum);
        return cnt;
    }
};
```