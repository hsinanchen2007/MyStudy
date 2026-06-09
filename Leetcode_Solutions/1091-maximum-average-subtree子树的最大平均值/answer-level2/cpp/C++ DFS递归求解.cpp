构造pair<int, int>结构
    - 存储<结点和，结点数>
    - 平均值 = 结点和/结点数：(double)sum/num

全局result用于节省空间，不需要额外数组保存中间均值结果


```C++
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
    double result = 0;
    double maximumAverageSubtree(TreeNode* root) {
        dfs(root);
        return result;
    }
private:
    pair<int, int> dfs(TreeNode* root){
        if(!root) return {0, 0};
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        int sum = left.first + right.first + root->val;
        int num = left.second + right.second + 1;
        result = max(result, (double)sum/num);
        return {sum, num};
    }
};
```