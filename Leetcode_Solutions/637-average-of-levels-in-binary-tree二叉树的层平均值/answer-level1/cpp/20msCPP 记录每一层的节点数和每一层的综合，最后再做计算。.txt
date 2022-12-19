### 解题思路
此处撰写解题思路

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
    vector<double> averageOfLevels(TreeNode* root) {
        int n = howlen(root);
        //cout << "n=" << n << endl;
        vector<double> sum(n,0);
        vector<double> count(n,0);
        vector<double> result(n,0);
        dfs(root,0,sum,count);
        for(int i = 0;i < n;i++)
            result[i] = sum[i] / count[i];
        return result;
    }
    void dfs(TreeNode* root,int level,vector<double>& sum,vector<double>& count)
    {
        if(!root) return;
        sum[level] += root->val;
        count[level] += 1;
        dfs(root->left,level+1,sum,count);
        dfs(root->right,level+1,sum,count);
    }

    int howlen(TreeNode* root)
    {
        if(!root) return 0;
        return max(howlen(root->left),howlen(root->right)) + 1;
    }
};
```