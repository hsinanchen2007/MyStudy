很垃圾，先层级遍历，然后使用reverse反过来
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
        if(root == NULL) return res;
        queue<TreeNode *> queTree;
        queTree.push(root);
        while(!queTree.empty()) {
            int size = queTree.size();
            vector<int> vecTemp;
            for (int i = 0;i < size; i++) {  
                TreeNode * temp = queTree.front();
                queTree.pop();
                vecTemp.push_back(temp->val);
                if(temp->left) queTree.push(temp->left);
                if(temp->right) queTree.push(temp->right);
            }
            res.push_back(vecTemp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```
