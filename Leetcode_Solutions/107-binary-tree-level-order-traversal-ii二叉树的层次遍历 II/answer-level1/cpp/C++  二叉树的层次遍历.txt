可参考102题我写的题解：
这题其实和102题的思路是一样的，先从顶部遍历，只是最后存储的方式不同（用rbegin和rend来逆序存储）。



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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        levelorder(root,0,res);
        return vector<vector<int>>(res.rbegin(),res.rend());
    }
        
    void levelorder(TreeNode* node, int level, vector<vector<int>>& res) 
    {
        if(!node) return ;
        if(res.size()==level) res.push_back({});
        res[level].push_back(node->val);
        if(node->left) levelorder(node->left,level+1, res);
        if(node->right) levelorder(node->right,level+1,res);
    }
    
};
```


