思路很简单：每次递归的时候判断当前结点是否可以更新第一最小值或第二最小值。
注意第一最小值和第二最小值不能相等

```
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
    int findSecondMinimumValue(TreeNode* root) {
        int minFirst = -1;
        int minSecond = -1;
        dfs(root, minFirst, minSecond);

        return minSecond;
    }

    void dfs(TreeNode* root, int& minFirst, int& minSecond)
    {
        if(root == nullptr) return;

        // 如果第一最小或第二最小还不存在，尝试更新
        if(minFirst == -1) minFirst = root->val;
        else if(minSecond == -1 && root->val != minFirst)
        {
            if(root->val < minFirst)
            {
                minSecond = minFirst;
                minFirst = root->val;
            }
            else minSecond = root->val;
        }

        // 尝试更新两者的值
        if(root->val < minSecond && root->val > minFirst) minSecond = root->val;
        else if(root->val < minFirst)
        {
            minSecond = minFirst;
            minFirst = root->val;
        }

        dfs(root->left, minFirst, minSecond);
        dfs(root->right, minFirst, minSecond);
    }
};
```
