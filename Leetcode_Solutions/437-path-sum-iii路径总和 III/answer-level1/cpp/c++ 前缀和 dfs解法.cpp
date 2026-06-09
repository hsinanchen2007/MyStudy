
思路：用到了前缀和的思想。
a的前缀和 = 从根节点到a节点的值加起来。
比如a节点到b节点之间和是target，那么   b的前缀和 - a的父节点的前缀和 = target；不明白可以自己手动演算一下
所以初始化vector后，先push_back(0)  当作根节点的父节点前缀和
然后dfs即可。

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
    int pathSum(TreeNode* root, int sum) {
        vector<int> prefixSum;
        int res = 0;
        dfs(root, prefixSum, sum, res);
        return res;
    }

    void dfs(TreeNode* root, vector<int>& prefixSum, int sum, int& res)
    {
        if (!root) return;
        
        int curPrefixSum =  root->val + prefixSum.empty() ? 0 : prefixSum[prefixSum.size()-1];

        for (auto it : prefixSum)
        {
            if (curPrefixSum - it == sum)
                ++res;
        }
        prefixSum.push_back(curPrefixSum);

        dfs(root->left, prefixSum, sum, res);
        dfs(root->right, prefixSum, sum, res);

        prefixSum.pop_back();
    }
};
```
