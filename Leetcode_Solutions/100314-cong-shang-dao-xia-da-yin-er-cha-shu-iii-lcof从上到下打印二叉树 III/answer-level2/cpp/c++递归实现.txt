### 解题思路
与上一题类似，本质上要判断层数的奇偶性，如果层数为奇数，说明本层要实现倒置，这里使用vector容器中的**insert**函数实现.

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        int level = 0;
        res = levelO(root, level, res);
        return res;

    }
    vector<vector<int>> levelO(TreeNode* root, int level, vector<vector<int>> &res){
        if(root == NULL)
            return res;
        if(res.size() == level)
            res.push_back({});
         if(level%2 == 0){
             res[level].push_back(root->val);
         }else{
             res[level].insert(res[level].begin(),root->val);
         }
        if(root->left!=NULL)
            levelO(root->left,level+1, res);
        if(root->right!=NULL)
            levelO(root->right, level+1, res);
        return res;
    }
};
```